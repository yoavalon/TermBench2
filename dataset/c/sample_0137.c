#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double* generate_data(int size) {
    double* data = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        data[i] = (double)rand() / RAND_MAX * 2 - 1; // Approximate normal distribution
    }
    return data;
}

double calculate_p_value(double* sample1, double* sample2, int size1, int size2) {
    double diff_mean = 0, pooled_std = 0;
    for (int i = 0; i < size1; i++) {
        diff_mean += sample1[i];
    }
    for (int i = 0; i < size2; i++) {
        diff_mean -= sample2[i];
    }
    diff_mean /= size1 + size2;

    double var1 = 0, var2 = 0;
    for (int i = 0; i < size1; i++) {
        var1 += (sample1[i] - diff_mean) * (sample1[i] - diff_mean);
    }
    for (int i = 0; i < size2; i++) {
        var2 += (sample2[i] - diff_mean) * (sample2[i] - diff_mean);
    }
    var1 /= size1;
    var2 /= size2;

    pooled_std = sqrt(var1 / size1 + var2 / size2);
    double t_stat = diff_mean / pooled_std;

    double* normal_samples = (double*)malloc(100000 * sizeof(double));
    for (int i = 0; i < 100000; i++) {
        normal_samples[i] = (double)rand() / RAND_MAX * 2 - 1; // Approximate normal distribution
    }

    double p_value = fabs(2 * (1 - t_stat));
    for (int i = 0; i < 100000; i++) {
        if (normal_samples[i] < t_stat) {
            p_value += 1;
        }
    }
    p_value /= 100000;

    free(normal_samples);
    return p_value;
}

int main() {
    srand(0);
    double* sample1 = generate_data(100);
    double* sample2 = generate_data(100);
    double p_value = calculate_p_value(sample1, sample2, 100, 100);
    printf("%f\n", p_value);
    free(sample1);
    free(sample2);
    return 0;
}