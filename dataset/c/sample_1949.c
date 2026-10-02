#include <stdio.h>
#include <math.h>

double calculate_precision(double a, double b) {
    double result = a / b;
    return result;
}

int check_convergence(double value, double threshold) {
    return fabs(value - 1) < threshold;
}

int main() {
    double a = 1.00000001;
    double b = 1.00000002;
    double precision = calculate_precision(a, b);
    while (!check_convergence(precision, 0.0001)) {
        a += 1e-08;
        b += 1e-08;
        precision = calculate_precision(a, b);
    }
    printf("%f\n", precision);
    return 0;
}