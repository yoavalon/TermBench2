#include <stdio.h>
#include <math.h>

double calculate_precision(double x, double y) {
    double a = x;
    double b = y;
    for (int i = 0; i < 100; i++) {
        a = (a + b) / 2;
        b = sqrt(a * b);
    }
    return a;
}

int analyze_convergence(double x, double y, double tolerance) {
    double precision = calculate_precision(x, y);
    return fabs(x - y) < tolerance;
}

int main() {
    double x = 1.41421356237;
    double y = 1.41421356238;
    double tolerance = 1e-10;
    int result = analyze_convergence(x, y, tolerance);
    printf("%d\n", result);
    return 0;
}