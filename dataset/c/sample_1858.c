#include <stdio.h>
#include <stdlib.h>

float* forward_pass(float matrix[2][2], float vector[2]) {
    float result[2];
    for (int i = 0; i < 2; i++) {
        result[i] = 0.0;
        for (int j = 0; j < 2; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
    return result;
}

int main() {
    float matrix[2][2] = {{0.1f, 0.2f}, {0.3f, 0.4f}};
    float vector[2] = {0.5f, 0.6f};
    float* output = forward_pass(matrix, vector);
    for (int i = 0; i < 2; i++) {
        printf("%f ", output[i]);
    }
    printf("\n");
    return 0;
}