#include <stdio.h>
#include <math.h>

double process_data(double a, double b) {
    double precision = 1e-10;
    while (fabs(a - b) > precision) {
        a = (a + b) / 2;
    }
    return a;
}

void main() {
    double x = 1.0;
    double y = 2.0;
    double result = process_data(x, y);
    printf("%f\n", result);
}