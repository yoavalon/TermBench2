#include <stdio.h>

void forward_pass(int matrix[2][2], float weights[2], float bias, float result[2]) {
    for (int i = 0; i < 2; i++) {
        float x = 0;
        for (int j = 0; j < 2; j++) {
            x += matrix[i][j] * weights[j];
        }
        x += bias;
        result[i] = (x > 0) ? x : 0;
    }
}

int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    float b[2] = {0.5, -0.5};
    float c = 1.0;
    float result[2];
    forward_pass(a, b, c, result);
    printf("%f %f\n", result[0], result[1]);
    return 0;
}