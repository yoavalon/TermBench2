#include <stdio.h>
#include <math.h>

double calculate_altitude() {
    double a = 1.0, b = 2.0, c = 3.0;
    double delta = b * b - 4 * a * c;
    if (delta >= 0) {
        return (-b + sqrt(delta)) / (2 * a);
    } else {
        return -1; // Using -1 to represent None
    }
}

void plan_trajectory(double *speed, double *altitude) {
    *altitude = calculate_altitude();
    if (*altitude != -1) {
        *speed = 0.8 * *altitude;
    } else {
        *speed = -1; // Using -1 to represent None
    }
}

int main() {
    double speed, altitude;
    plan_trajectory(&speed, &altitude);
    if (speed != -1 && altitude != -1) {
        printf("Speed: %f, Altitude: %f\n", speed, altitude);
    } else {
        printf("No valid trajectory.\n");
    }
    return 0;
}