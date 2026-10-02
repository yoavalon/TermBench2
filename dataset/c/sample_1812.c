#include <stdio.h>

double calculate_altitude(double time, double speed, double gravity, double initial_altitude) {
    double altitude = initial_altitude + speed * time - 0.5 * gravity * time * time;
    return altitude;
}

void main() {
    double a = calculate_altitude(10, 200, 9.81, 5000);
    printf("%f\n", a);
}