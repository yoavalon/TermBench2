#include <stdio.h>

void forward_pass(int matrix[2][2], float weights[2][2], float bias[2], float result[2]) {
    for (int i = 0; i < 2; i++) {
        result[i] = 0;
        for (int j = 0; j < 2; j++) {
            result[i] += matrix[i][j] * weights[j][i];
        }
        result[i] += bias[i];
    }
}

int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    float w[2][2] = {{0.1, 0.2}, {0.3, 0.4}};
    float b[2] = {0.5, 0.6};
    float result[2];

    forward_pass(a, w, b, result);

    printf("%f %f\n", result[0], result[1]);

    return 0;
}