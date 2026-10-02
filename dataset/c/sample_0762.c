#include <stdio.h>
#include <stdlib.h>

void permute(int *data, int n, int *result, int *result_index, int depth, int *temp, int *temp_index) {
    if (depth == n) {
        for (int i = 0; i < n; i++) {
            result[result_index[0] * n + i] = temp[i];
        }
        result_index[0]++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (temp_index[i] == 0) {
            temp[depth] = data[i];
            temp_index[i] = 1;
            permute(data, n, result, result_index, depth + 1, temp, temp_index);
            temp_index[i] = 0;
        }
    }
}

double calculate_pvalue(int *data, int n, double (*func)(int*, int)) {
    double observed = func(data, n);
    int *result = (int *)malloc(n * (n - 1) * sizeof(int));
    int *result_index = (int *)calloc(1, sizeof(int));
    int *temp = (int *)malloc(n * sizeof(int));
    int *temp_index = (int *)calloc(n, sizeof(int));
    permute(data, n, result, result_index, 0, temp, temp_index);
    double p_values[result_index[0]];
    for (int i = 0; i < result_index[0]; i++) {
        p_values[i] = func(&result[i * n], n - 1);
    }
    free(result);
    free(result_index);
    free(temp);
    free(temp_index);
    int count = 0;
    for (int i = 0; i < result_index[0]; i++) {
        if (p_values[i] >= observed) {
            count++;
        }
    }
    return (double)count / result_index[0];
}

double statistic_func(int *x, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += x[i];
    }
    double mean1 = (double)sum / n;
    int sum2 = 1 + 2 + 3 + 4 + 5;
    double mean2 = (double)sum2 / 5;
    return mean1 - mean2;
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int n = sizeof(data) / sizeof(data[0]);
    double p_value = calculate_pvalue(data, n, statistic_func);
    printf("%f\n", p_value);
    return 0;
}