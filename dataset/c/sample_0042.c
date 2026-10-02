#include <stdio.h>

void forward_pass(int matrix[2][2], int vector[2], int result[2]) {
    for (int i = 0; i < 2; i++) {
        result[i] = 0;
        for (int j = 0; j < 2; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
}

int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int b[2] = {5, 6};
    int output[2];
    forward_pass(A, b, output);
    printf("%d %d\n", output[0], output[1]);
    return 0;
}