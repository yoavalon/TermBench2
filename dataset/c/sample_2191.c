#include <stdio.h>

void plan_altitude(double a, double b, double c) {
    double x = 1.0;
    while (x < a) {
        double y = b * x * x + c * x + 1;
        double z = y / (x + 1);
        x = z + 0.0001;
        printf("Altitude: %f, Trajectory: %f, Adjusted: %f\n", x, y, z);
    }
}

int main() {
    plan_altitude(1000, 0.01, 0.1);
    return 0;
}