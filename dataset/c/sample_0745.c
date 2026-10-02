#include <stdio.h>
#include <stdlib.h>

void permute(int *data, int index, int *result, int **results, int *result_count, int n) {
    if (index == n) {
        results[*result_count] = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            results[*result_count][i] = result[i];
        }
        (*result_count)++;
    } else {
        for (int i = 0; i < n; i++) {
            int found = 0;
            for (int j = 0; j < index; j++) {
                if (data[i] == result[j]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                result[index] = data[i];
                permute(data, index + 1, result, results, result_count, n);
            }
        }
    }
}

double calculate_pvalue(int *data1, int *data2, int n1, int n2) {
    int n = n1 + n2;
    int *combined = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n1; i++) {
        combined[i] = data1[i];
    }
    for (int i = 0; i < n2; i++) {
        combined[i + n1] = data2[i];
    }

    double original_mean_diff = (double)(n1 * n2 * (n1 * n2 + 1)) / (2 * n1 * n2) - (double)(n1 * (n1 + 1)) / 2 - (double)(n2 * (n2 + 1)) / 2;
    int count_greater = 0;
    int **permutations = (int **)malloc(100000 * sizeof(int *));
    int result_count = 0;
    int *result = (int *)malloc(n * sizeof(int));
    permute(combined, 0, result, permutations, &result_count, n);

    for (int i = 0; i < result_count; i++) {
        int *perm = permutations[i];
        double mean1 = 0, mean2 = 0;
        for (int j = 0; j < n1; j++) {
            mean1 += perm[j];
        }
        for (int j = n1; j < n; j++) {
            mean2 += perm[j];
        }
        mean1 /= n1;
        mean2 /= n2;
        if (mean1 - mean2 >= original_mean_diff) {
            count_greater++;
        }
        free(perm);
    }
    free(combined);
    free(permutations);
    free(result);
    return (double)count_greater / result_count;
}

int main() {
    int data1[] = {1, 2, 3, 4};
    int data2[] = {5, 6, 7, 8};
    int n1 = sizeof(data1) / sizeof(data1[0]);
    int n2 = sizeof(data2) / sizeof(data2[0]);
    double pvalue = calculate_pvalue(data1, data2, n1, n2);
    printf("%f\n", pvalue);
    return 0;
}