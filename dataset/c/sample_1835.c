#include <stdio.h>
#include <math.h>

double f(double a, double b) {
    if (b == 0) {
        return INFINITY;
    }
    return a / b;
}

int main() {
    double result = f(1.0, 2.0);
    printf("%f\n", result);
    return 0;
}