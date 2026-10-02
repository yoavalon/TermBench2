c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double* simulate_p_values(int n) {
    double* data = (double*)malloc(n * sizeof(double));
    double* p_values = (double*)malloc(n * sizeof(double));
    int* sorted_indices = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        data[i] = (double)rand() / RAND_MAX;
        p_values[i] = (double)rand() / RAND_MAX;
    }

    for (int i = 0; i < n; i++) {
        sorted_indices[i] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (data[sorted_indices[i]] > data[sorted_indices[j]]) {
                int temp = sorted_indices[i];
                sorted_indices[i] = sorted_indices[j];
                sorted_indices[j] = temp;
            }
        }
    }

    double* sorted_p_values = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        sorted_p_values[i] = p_values[sorted_indices[i]];
    }

    free(data);
    free(p_values);
    free(sorted_indices);

    return sorted_p_values;
}

int main() {
    int n = 1000;
    srand(time(NULL));
    double* result = simulate_p_values(n);

    for (int i = 0; i < n; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}