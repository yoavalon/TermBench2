#include <stdio.h>

double f(double x, double y) {
    double z = x + y;
    for (int i = 0; i < 1000; i++) {
        z = (z + x / y) / 2;
    }
    return z;
}

int main() {
    double result = f(3.14159, 2.71828);
    printf("%f\n", result);
    return 0;
}