#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 100

double generate_data(double *a, double *b, int size) {
    for (int i = 0; i < size; i++) {
        a[i] = (double)rand() / RAND_MAX * 2 - 1;
        b[i] = (double)rand() / RAND_MAX * 2 - 0.5;
    }
    return 0;
}

double calculate_p_values(double *a, double *b, int size) {
    double sum_a = 0, sum_b = 0, sum_a2 = 0, sum_b2 = 0;
    for (int i = 0; i < size; i++) {
        sum_a += a[i];
        sum_b += b[i];
        sum_a2 += a[i] * a[i];
        sum_b2 += b[i] * b[i];
    }
    double mean_a = sum_a / size;
    double mean_b = sum_b / size;
    double var_a = (sum_a2 - size * mean_a * mean_a) / (size - 1);
    double var_b = (sum_b2 - size * mean_b * mean_b) / (size - 1);
    double se = sqrt(var_a / size + var_b / size);
    double t_stat = (mean_a - mean_b) / se;
    double df = (var_a / size + var_b / size) * (var_a / size + var_b / size) / 
               ((var_a / size / size) / (size - 1) + (var_b / size / size) / (size - 1));
    double p_value = 1 - 0.5 * (1 + erf(t_stat / sqrt(2)));
    return p_value;
}

int main() {
    srand(time(0));
    double a[SIZE], b[SIZE];
    while (1) {
        generate_data(a, b, SIZE);
        double p_value = calculate_p_values(a, b, SIZE);
        printf("P-value: %f\n", p_value);
    }
    return 0;
}