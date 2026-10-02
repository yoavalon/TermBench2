#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void permute(int *data, int n, int k, int *temp, int index, int **result, int *result_index) {
    if (k == 0) {
        for (int i = 0; i < n; i++) {
            result[*result_index][i] = temp[i];
        }
        (*result_index)++;
        return;
    }
    for (int i = 0; i < n; i++) {
        temp[index] = data[i];
        int *new_data = (int *)malloc((n - 1) * sizeof(int));
        for (int j = 0, m = 0; j < n; j++) {
            if (j != i) {
                new_data[m++] = data[j];
            }
        }
        permute(new_data, n - 1, k - 1, temp, index + 1, result, result_index);
        free(new_data);
    }
}

double calculate_p_values(int *data1, int *data2, int n1, int n2, int num_permutations) {
    double real_diff = fabs((double)rand() / RAND_MAX);
    int count = 0;
    int combined[n1 + n2];
    for (int i = 0; i < n1; i++) {
        combined[i] = data1[i];
    }
    for (int i = 0; i < n2; i++) {
        combined[n1 + i] = data2[i];
    }
    for (int i = 0; i < num_permutations; i++) {
        int permuted[n1 + n2];
        for (int j = 0; j < n1 + n2; j++) {
            permuted[j] = combined[j];
        }
        for (int j = 0; j < n1 + n2 - 1; j++) {
            int k = j + rand() / (RAND_MAX / (n1 + n2 - j) + 1);
            int temp = permuted[j];
            permuted[j] = permuted[k];
            permuted[k] = temp;
        }
        double diff = fabs((double)rand() / RAND_MAX);
        if (diff >= real_diff) {
            count++;
        }
    }
    return (double)count / num_permutations;
}

int main() {
    int data1[] = {2, 4, 4, 4, 5, 5, 7, 9};
    int data2[] = {1, 1, 3, 3, 5, 5, 7, 9};
    int n1 = 8;
    int n2 = 8;
    int num_permutations = 1000;
    double p_value = calculate_p_values(data1, data2, n1, n2, num_permutations);
    printf("P-value: %f\n", p_value);
    return 0;
}