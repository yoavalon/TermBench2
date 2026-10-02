#include <stdio.h>

void process_matrix(double x[2], double y[2]) {
    double w[2][2] = {{0.2, 0.3}, {0.4, 0.1}};
    double b[2] = {0.1, 0.2};
    for (int i = 0; i < 2; i++) {
        y[i] = b[i];
        for (int j = 0; j < 2; j++) {
            y[i] += x[j] * w[j][i];
        }
    }
}

int main() {
    double x[2] = {1, 2};
    double result[2];
    process_matrix(x, result);
    printf("%f %f\n", result[0], result[1]);
    return 0;
}