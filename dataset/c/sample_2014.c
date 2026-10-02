#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double generate_data(int size) {
    double data[size];
    for (int i = 0; i < size; i++) {
        data[i] = rand() / (double)RAND_MAX * 2 - 1;
    }
    return data[0];
}

double calculate_p_value(double *data1, double *data2, int size1, int size2) {
    double mean1 = 0, mean2 = 0;
    for (int i = 0; i < size1; i++) {
        mean1 += data1[i];
    }
    mean1 /= size1;
    for (int i = 0; i < size2; i++) {
        mean2 += data2[i];
    }
    mean2 /= size2;

    double variance1 = 0, variance2 = 0;
    for (int i = 0; i < size1; i++) {
        variance1 += (data1[i] - mean1) * (data1[i] - mean1);
    }
    variance1 /= size1;
    for (int i = 0; i < size2; i++) {
        variance2 += (data2[i] - mean2) * (data2[i] - mean2);
    }
    variance2 /= size2;

    double pooled_variance = ((size1 - 1) * variance1 + (size2 - 1) * variance2) / (size1 + size2 - 2);
    double t_statistic = (mean1 - mean2) / sqrt(pooled_variance * (1.0 / size1 + 1.0 / size2));
    int df = size1 + size2 - 2;
    double p_value = 2 * (1 - tanh(t_statistic * sqrt(df / (df + t_statistic * t_statistic))));
    return p_value;
}

void simulate_p_values(int num_simulations, int sample_size, double *p_values) {
    for (int i = 0; i < num_simulations; i++) {
        double data1[sample_size], data2[sample_size];
        for (int j = 0; j < sample_size; j++) {
            data1[j] = generate_data(sample_size);
            data2[j] = generate_data(sample_size);
        }
        p_values[i] = calculate_p_value(data1, data2, sample_size, sample_size);
    }
}

int compare(const void *a, const void *b) {
    return (*(double*)a > *(double*)b) - (*(double*)a < *(double*)b);
}

int main() {
    int num_simulations = 1000;
    int sample_size = 30;
    double p_values[num_simulations];
    simulate_p_values(num_simulations, sample_size, p_values);
    qsort(p_values, num_simulations, sizeof(double), compare);
    double median_p_value = p_values[num_simulations / 2];
    printf("Median P-value: %f\n", median_p_value);
    return 0;
}