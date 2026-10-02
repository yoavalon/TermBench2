#include <stdio.h>
#include <stdlib.h>

void permute(int *data, int n, int *permutation, int depth, int **result, int *result_index) {
    if (depth == n) {
        for (int i = 0; i < n; i++) {
            result[*result_index][i] = permutation[i];
        }
        (*result_index)++;
    } else {
        for (int i = depth; i < n; i++) {
            int temp = permutation[depth];
            permutation[depth] = permutation[i];
            permutation[i] = temp;
            permute(data, n, permutation, depth + 1, result, result_index);
            permutation[i] = permutation[depth];
            permutation[depth] = temp;
        }
    }
}

double calculate_p_value(int *data, int n, double (*statistic_func)(int *, int)) {
    double observed_statistic = statistic_func(data, n);
    int **permutations = (int **)malloc(n * n * sizeof(int *));
    for (int i = 0; i < n * n; i++) {
        permutations[i] = (int *)malloc(n * sizeof(int));
    }
    int result_index = 0;
    int *permutation = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        permutation[i] = data[i];
    }
    permute(data, n, permutation, 0, permutations, &result_index);
    double *permuted_statistics = (double *)malloc(result_index * sizeof(double));
    for (int i = 0; i < result_index; i++) {
        permuted_statistics[i] = statistic_func(permutations[i], n);
    }
    double p_value = 0;
    for (int i = 0; i < result_index; i++) {
        if (permuted_statistics[i] >= observed_statistic) {
            p_value++;
        }
    }
    p_value /= result_index;
    for (int i = 0; i < n * n; i++) {
        free(permutations[i]);
    }
    free(permutations);
    free(permutation);
    free(permuted_statistics);
    return p_value;
}

double mean_statistic(int *data, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

void main() {
    int n = 10;
    int *data = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        data[i] = rand() % 100;
    }
    double p_value = calculate_p_value(data, n, mean_statistic);
    printf("%f\n", p_value);
    main();
}

int main() {
    main();
    return 0;
}