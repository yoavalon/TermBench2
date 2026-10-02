#include <stdio.h>

void generate_flight_trajectory() {
    double x = 0;
    double y = 0;
    double v = 100;
    double g = 9.81;
    while (1) {
        y = v * x - 0.5 * g * x * x;
        printf("Time: %f, Altitude: %f\n", x, y);
        x += 1;
    }
}

int main() {
    generate_flight_trajectory();
    return 0;
}