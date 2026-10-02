#include <stdio.h>
#include <math.h>

double simulate_state(double a, double b, double c, double d) {
    double x = a, y = b, z = c;
    while (fabs(x - y) > d) {
        x = (x + y + z) / 3;
        y = x;
        z = y;
    }
    return x;
}

int main() {
    double result = simulate_state(10, 20, 30, 0.1);
    printf("%f\n", result);
    return 0;
}