#include <stdio.h>
#include <math.h>

double tanh(double x) {
    return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
}

double data_mutations(double matrix[2][2], double weights[2][2], double bias[2], double result[2]) {
    for (int i = 0; i < 2; i++) {
        result[i] = 0.0;
        for (int j = 0; j < 2; j++) {
            result[i] += matrix[i][j] * weights[j][i];
        }
        result[i] += bias[i];
        result[i] = tanh(result[i]);
    }
    return result[0];
}

int main() {
    double a[2][2] = {{1, 2}, {3, 4}};
    double b[2][2] = {{0.1, 0.2}, {0.3, 0.4}};
    double c[2] = {0.1, 0.2};
    double result[2];
    data_mutations(a, b, c, result);
    printf("%f %f\n", result[0], result[1]);
    return 0;
}