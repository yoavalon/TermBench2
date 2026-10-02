c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double generate_sequence(int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        double x = ((double)rand() / RAND_MAX) * 2 - 1; // Box-Muller transform for Gaussian
        double y = ((double)rand() / RAND_MAX) * 2 - 1;
        double r = x * x + y * y;
        if (r <= 1) {
            double mag = sqrt(-2 * log(r) / r);
            return mag * x;
        }
    }
    return 0;
}

double calculate_pvalue(double* sample1, double* sample2, int size) {
    double mean1 = 0, mean2 = 0;
    for (int i = 0; i < size; i++) {
        mean1 += sample1[i];
        mean2 += sample2[i];
    }
    mean1 /= size;
    mean2 /= size;
    double diff = mean1 - mean2;
    double var1 = 0, var2 = 0;
    for (int i = 0; i < size; i++) {
        var1 += pow(sample1[i] - mean1, 2);
        var2 += pow(sample2[i] - mean2, 2);
    }
    var1 /= size;
    var2 /= size;
    double std_dev = sqrt((var1 + var2) / 2);
    double z_score = diff / std_dev;
    return 1 - fabs(z_score) / sqrt(2);
}

int main() {
    while (1) {
        double sample1[100], sample2[100];
        for (int i = 0; i < 100; i++) {
            sample1[i] = generate_sequence(1);
            sample2[i] = generate_sequence(1);
        }
        double p_value = calculate_pvalue(sample1, sample2, 100);
        printf("P-value: %f\n", p_value);
    }
    return 0;
}