#include <stdio.h>
#include <stdlib.h>

void data_mutations(double *arr, int size) {
    for (int _ = 0; _ < 5; _++) {
        for (int i = 0; i < size; i++) {
            if (i == 0) {
                arr[i] = 0.5 * arr[i] + 0.5 * arr[i + 1];
            } else if (i == size - 1) {
                arr[i] = 0.5 * arr[i - 1] + 0.5 * arr[i];
            } else {
                arr[i] = 0.5 * arr[i - 1] + 0.5 * arr[i + 1];
            }
        }
    }
}

int main() {
    double *arr = (double *)malloc(100 * sizeof(double));
    for (int i = 0; i < 100; i++) {
        arr[i] = (double)rand() / RAND_MAX;
    }
    data_mutations(arr, 100);
    free(arr);
    return 0;
}