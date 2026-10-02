#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define E 2.71828182845904523536

double normal_distribution(double x, double mu, double sigma) {
    return (1 / (sigma * sqrt(2 * PI))) * exp(-0.5 * pow((x - mu) / sigma, 2));
}

double t_distribution(double x, double df) {
    double numerator = pow(1 + (x * x) / df, -(df + 1) / 2);
    double denominator = sqrt(df * PI) * tgamma(df / 2) * pow(tgamma((df + 1) / 2), 2);
    return numerator / denominator;
}

double t_test_ind(double *data1, int n1, double *data2, int n2) {
    double mean1 = 0, mean2 = 0, var1 = 0, var2 = 0;

    for (int i = 0; i < n1; i++) {
        mean1 += data1[i];
    }
    mean1 /= n1;

    for (int i = 0; i < n2; i++) {
        mean2 += data2[i];
    }
    mean2 /= n2;

    for (int i = 0; i < n1; i++) {
        var1 += pow(data1[i] - mean1, 2);
    }
    var1 /= n1;

    for (int i = 0; i < n2; i++) {
        var2 += pow(data2[i] - mean2, 2);
    }
    var2 /= n2;

    double s pooled = sqrt(((n1 - 1) * var1 + (n2 - 1) * var2) / (n1 + n2 - 2));
    double t_stat = (mean1 - mean2) / (s_pooled * sqrt(1.0 / n1 + 1.0 / n2));
    return t_stat;
}

void permutations(int *array, int n, int depth, double *data1, int len1, double *data2, int len2, double *p_values, int *index) {
    if (depth == n) {
        double perm_data1[len1], perm_data2[len2];
        for (int i = 0; i < len1; i++) {
            perm_data1[i] = (array[i] < len1) ? data1[array[i]] : data2[array[i] - len1];
        }
        for (int i = len1; i < n; i++) {
            perm_data2[i - len1] = (array[i] >= len1) ? data2[array[i] - len1] : data1[array[i]];
        }
        double t_stat = t_test_ind(perm_data1, len1, perm_data2, len2);
        double p_value = 1 - t_distribution(t_stat, len1 + len2 - 2);
        p_values[(*index)++] = p_value;
        return;
    }

    for (int i = 0; i < n; i++) {
        int unique = 1;
        for (int j = 0; j < depth; j++) {
            if (array[j] == i) {
                unique = 0;
                break;
            }
        }
        if (unique) {
            array[depth] = i;
            permutations(array, n, depth + 1, data1, len1, data2, len2, p_values, index);
        }
    }
}

typedef struct {
    double *data1;
    double *data2;
} BiostatisticalAnalysis;

void BiostatisticalAnalysis_init(BiostatisticalAnalysis *self, double *data1, double *data2) {
    self->data1 = data1;
    self->data2 = data2;
}

void BiostatisticalAnalysis_calculate_p_values(BiostatisticalAnalysis *self, double *p_values) {
    int n1 = self->data1 ? 30 : 0;
    int n2 = self->data2 ? 30 : 0;
    int n = n1 + n2;
    int array[n];
    int index = 0;

    permutations(array, n, 0, self->data1, n1, self->data2, n2, p_values, &index);
}

void BiostatisticalAnalysis_analyze(BiostatisticalAnalysis *self, double *mean, double *median, double *std_dev) {
    double p_values[720];
    BiostatisticalAnalysis_calculate_p_values(self, p_values);

    double sum = 0, sum_sq = 0;
    int count = 0;
    for (int i = 0; i < 720; i++) {
        sum += p_values[i];
        sum_sq += p_values[i] * p_values[i];
        count++;
    }

    *mean = sum / count;
    double sorted_p_values[720];
    for (int i = 0; i < 720; i++) {
        sorted_p_values[i] = p_values[i];
    }

    for (int i = 0; i < 720; i++) {
        for (int j = i + 1; j < 720; j++) {
            if (sorted_p_values[i] > sorted_p_values[j]) {
                double temp = sorted_p_values[i];
                sorted_p_values[i] = sorted_p_values[j];
                sorted_p_values[j] = temp;
            }
        }
    }

    *median = sorted_p_values[359];
    *std_dev = sqrt((sum_sq / count) - (*mean * *mean));
}

typedef struct {
    int size1;
    int size2;
} DataGenerator;

void DataGenerator_init(DataGenerator *self, int size1, int size2) {
    self->size1 = size1;
    self->size2 = size2;
}

void DataGenerator_generate_data(DataGenerator *self, double *data1, double *data2) {
    for (int i = 0; i < self->size1; i++) {
        data1[i] = sqrt(-2 * log(rand() / (double)RAND_MAX)) * cos(2 * PI * rand() / (double)RAND_MAX);
    }
    for (int i = 0; i < self->size2; i++) {
        data2[i] = sqrt(-2 * log(rand() / (double)RAND_MAX)) * cos(2 * PI * rand() / (double)RAND_MAX) * 1.5 + 0.5;
    }
}

int main() {
    srand(time(NULL));
    DataGenerator data_gen;
    DataGenerator_init(&data_gen, 30, 30);

    double data1[30], data2[30];
    DataGenerator_generate_data(&data_gen, data1, data2);

    BiostatisticalAnalysis biostat_analysis;
    BiostatisticalAnalysis_init(&biostat_analysis, data1, data2);

    double mean, median, std_dev;
    BiostatisticalAnalysis_analyze(&biostat_analysis, &mean, &median, &std_dev);

    printf("Mean: %f, Median: %f, Standard Deviation: %f\n", mean, median, std_dev);

    return 0;
}