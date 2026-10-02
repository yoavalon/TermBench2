#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int *data, int i, int length, int **result, int *result_index) {
    if (i == length) {
        result[*result_index] = (int *)malloc(length * sizeof(int));
        for (int j = 0; j < length; j++) {
            result[*result_index][j] = data[j];
        }
        (*result_index)++;
    } else {
        for (int j = i; j < length; j++) {
            swap(&data[i], &data[j]);
            permute(data, i + 1, length, result, result_index);
            swap(&data[i], &data[j]);
        }
    }
}

double calculate_pvalue(int *data, int length, double (*test_statistic)(int *, int), int n_permutations) {
    double observed_stat = test_statistic(data, length);
    int **permutations = (int **)malloc(n_permutations * sizeof(int *));
    int result_index = 0;
    permute(data, 0, length, permutations, &result_index);
    double *perm_stats = (double *)malloc(result_index * sizeof(double));
    for (int i = 0; i < result_index; i++) {
        perm_stats[i] = test_statistic(permutations[i], length);
        free(permutations[i]);
    }
    free(permutations);
    double pvalue = 0;
    for (int i = 0; i < result_index; i++) {
        if (perm_stats[i] >= observed_stat) {
            pvalue++;
        }
    }
    free(perm_stats);
    return pvalue / n_permutations;
}

double test_statistic(int *data, int length) {
    double sum = 0;
    for (int i = 0; i < length; i++) {
        sum += data[i];
    }
    return sum;
}

void main() {
    int data[] = {1, 2, 3, 4, 5};
    int length = sizeof(data) / sizeof(data[0]);
    int n_permutations = 100;
    double pvalue = calculate_pvalue(data, length, test_statistic, n_permutations);
    printf("%f\n", pvalue);
}