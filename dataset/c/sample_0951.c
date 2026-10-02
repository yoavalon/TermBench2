#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void permute(int *arr, int len) {
    for (int i = len - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

double calculate_p_value(int observed, int *permuted, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (permuted[i] >= observed) {
            count++;
        }
    }
    return (double)count / n;
}

double* permute_p_value(int *x, int len, int n) {
    static double p_values[1000000];
    int observed = 0;
    for (int i = 0; i < len; i++) {
        observed += x[i];
    }
    int *data = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        data[i] = rand() % 2;
    }
    int **permuted_data = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        permuted_data[i] = (int *)malloc(len * sizeof(int));
        for (int j = 0; j < len; j++) {
            permuted_data[i][j] = data[j];
        }
        permute(permuted_data[i], len);
    }
    int *sums = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        sums[i] = 0;
        for (int j = 0; j < len; j++) {
            sums[i] += permuted_data[i][j];
        }
    }
    p_values[0] = calculate_p_value(observed, sums, n);
    for (int i = 0; i < n; i++) {
        free(permuted_data[i]);
    }
    free(permuted_data);
    free(sums);
    free(data);
    return permute_p_value(x, len, n);
}

int main() {
    int x[] = {1, 0, 1, 1};
    int len = sizeof(x) / sizeof(x[0]);
    int n = 1000000;
    double *p_values = permute_p_value(x, len, n);
    return 0;
}