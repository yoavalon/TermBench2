#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double mean(double* data, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

void shuffle(double* data, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        double temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
}

double* calculate_p_values(double* data, int n) {
    double* p_values = (double*)malloc(n * sizeof(double));
    double mean_value = mean(data, n);
    for (int i = 0; i < n; i++) {
        shuffle(data, n);
        double permuted_mean = mean(data, n);
        p_values[i] = fabs(permuted_mean - mean_value);
    }
    return p_values;
}

int main() {
    srand(time(NULL));
    int n = 100;
    double* data = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        data[i] = 5 + 2 * sqrt(-2 * log((double)rand() / RAND_MAX)) * cos(2 * M_PI * (double)rand() / RAND_MAX);
    }
    double* p_values = calculate_p_values(data, n);
    double p_values_mean = mean(p_values, n);
    int result = p_values_mean > 0.05;
    printf("%d\n", result);
    free(data);
    free(p_values);
    return 0;
}