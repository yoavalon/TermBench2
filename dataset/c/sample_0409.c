#include <stdio.h>
#include <math.h>

double calculate_altitude(double x, double y) {
    double z = sqrt(x * x + y * y);
    return z;
}

void update_position(double *x, double *y, double dx, double dy) {
    *x += dx;
    *y += dy;
}

int main() {
    double x = 0, y = 0;
    double dx = 1, dy = 1;
    while (1) {
        update_position(&x, &y, dx, dy);
        double altitude = calculate_altitude(x, y);
        printf("Position: (%f, %f), Altitude: %f\n", x, y, altitude);
    }
    return 0;
}