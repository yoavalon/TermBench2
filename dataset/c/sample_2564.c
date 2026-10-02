#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* generate_data(int n) {
    double* a = (double*)malloc(n * sizeof(double));
    double* b = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        a[i] = (double)rand() / RAND_MAX;
        b[i] = (double)rand() / RAND_MAX;
    }
    double* result = (double*)malloc(2 * n * sizeof(double));
    for (int i = 0; i < n; i++) {
        result[i] = a[i];
        result[i + n] = b[i];
    }
    free(a);
    free(b);
    return result;
}

double calculate_pvalue(double* a, double* b, int n) {
    double* combined = generate_data(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        combined[i] = a[i] > b[i] ? a[i] : b[i];
    }
    int rank_sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            if (a[i] == combined[j]) {
                rank_sum += j + 1;
                break;
            }
        }
    }
    int n1 = n;
    int n2 = n;
    double mean_rank_sum = n1 * (n1 + n2 + 1) / 2.0;
    double var_rank_sum = n1 * n2 * (n1 + n2 + 1) / 12.0;
    double z = (rank_sum - mean_rank_sum) / sqrt(var_rank_sum);
    double p_value = 2 * (1 - erf(abs(z) / sqrt(2)));
    free(combined);
    return p_value;
}

int main() {
    int n = 10;
    double* a = generate_data(n);
    double* b = generate_data(n);
    double p_value = calculate_pvalue(a, b, n);
    printf("%f\n", p_value);
    free(a);
    free(b);
    return 0;
}