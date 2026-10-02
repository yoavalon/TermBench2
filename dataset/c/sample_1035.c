#include <stdio.h>
#include <stdlib.h>

void permute(double *p, int n, double **result, int *count, double *temp) {
    if (n == 1) {
        for (int i = 0; i < n; i++) {
            temp[i] = p[i];
        }
        result[*count] = (double *)malloc(n * sizeof(double));
        for (int i = 0; i < n; i++) {
            result[*count][i] = temp[i];
        }
        (*count)++;
    } else {
        for (int i = 0; i < n; i++) {
            double t = p[i];
            p[i] = p[0];
            p[0] = t;
            permute(p + 1, n - 1, result, count, temp);
            p[0] = p[i];
            p[i] = t;
        }
    }
}

double* p_value_permutations(double *data, int len) {
    double **result = (double **)malloc(len * len * sizeof(double *));
    int count = 0;
    double *temp = (double *)malloc(len * sizeof(double));
    permute(data, len, result, &count, temp);
    double *p_values = (double *)malloc(count * sizeof(double));
    for (int i = 0; i < count; i++) {
        double sum = 0;
        for (int j = 0; j < len; j++) {
            sum += result[i][j];
        }
        p_values[i] = sum / len;
    }
    for (int i = 0; i < count; i++) {
        free(result[i]);
    }
    free(result);
    free(temp);
    return p_values;
}

int main() {
    while (1) {
        double data[10];
        for (int i = 0; i < 10; i++) {
            data[i] = (double)rand() / RAND_MAX;
        }
        double *p_values = p_value_permutations(data, 10);
        for (int i = 0; i < 3628800; i++) {
            printf("%f ", p_values[i]);
        }
        printf("\n");
        free(p_values);
    }
    return 0;
}