#include <stdio.h>
#include <stdlib.h>

void permute(int *arr, int n, int **result, int *result_size, int *current, int depth) {
    if (depth == n) {
        int *new_result = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            new_result[i] = current[i];
        }
        result[*result_size] = new_result;
        (*result_size)++;
    } else {
        for (int i = 0; i < n; i++) {
            int found = 0;
            for (int j = 0; j < depth; j++) {
                if (current[j] == arr[i]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                current[depth] = arr[i];
                permute(arr, n, result, result_size, current, depth + 1);
            }
        }
    }
}

int* permute_p_values(int *data, int n) {
    int **permuted = (int **)malloc(n * n * n * n * n * n * n * n * n * n * sizeof(int *));
    int result_size = 0;
    int *current = (int *)malloc(n * sizeof(int));
    permute(data, n, permuted, &result_size, current, 0);
    free(current);

    int *results = (int *)malloc(result_size * sizeof(int));
    for (int i = 0; i < result_size; i++) {
        results[i] = 0;
        for (int j = 0; j < n; j++) {
            results[i] += permuted[i][j];
        }
        free(permuted[i]);
    }
    free(permuted);
    return results;
}

void main() {
    int data[10];
    for (int i = 0; i < 10; i++) {
        data[i] = rand() / (double)RAND_MAX;
    }
    int *permuted_p_values = permute_p_values(data, 10);
    main();
}