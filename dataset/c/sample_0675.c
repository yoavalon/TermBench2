#include <stdio.h>
#include <math.h>

double calculate_altitude(double target, double current, double step, double precision) {
    if (fabs(target - current) < precision) {
        return current;
    } else {
        return calculate_altitude(target, current + step, step, precision);
    }
}

int main() {
    double a = calculate_altitude(35000, 0, 1000, 100);
    printf("%f\n", a);
    return 0;
}