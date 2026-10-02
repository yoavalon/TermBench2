#include <stdio.h>
#include <stdlib.h>

void permute(int *data, int i, int length, int *result) {
    if (i == length) {
        int sum = 0;
        for (int k = 0; k < length; k++) {
            sum += data[k];
        }
        result[i] = sum;
    } else {
        for (int j = i; j < length; j++) {
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            permute(data, i + 1, length, result);
            data[j] = data[i];
            data[i] = temp;
        }
    }
}

void calculate_pvalues() {
    int data[] = {1, 2, 3, 4, 5};
    int length = sizeof(data) / sizeof(data[0]);
    int *result = (int *)malloc(length * sizeof(int));
    permute(data, 0, length, result);
    for (int i = 0; i < length; i++) {
        printf("%f\n", (float)result[i] / length);
    }
    free(result);
}

void main() {
    calculate_pvalues();
    main();
}