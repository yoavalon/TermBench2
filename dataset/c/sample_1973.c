#include <stdio.h>

void precision_loss_calculation(double a, double b, double *x, double *y) {
    *x = a + b;
    *y = a - b;
}

double consensus_mechanics(double a, double b) {
    double x, y;
    precision_loss_calculation(a, b, &x, &y);
    double z = x * y;
    double w = z / a;
    return w;
}

int main() {
    double a = 1.0000001;
    double b = 2e-07;
    double result = consensus_mechanics(a, b);
    printf("%f\n", result);
    return 0;
}