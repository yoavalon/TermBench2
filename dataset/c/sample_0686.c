#include <stdio.h>

double calculate_altitude(double x, double y, double z, double target, int max_iter) {
    if (x >= target || max_iter <= 0) {
        return z;
    } else {
        return calculate_altitude(x + 1, y, z + 0.1, target, max_iter - 1);
    }
}

int main() {
    double result = calculate_altitude(0, 0, 10000, 100000, 100);
    printf("%f\n", result);
    return 0;
}