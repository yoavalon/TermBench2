#include <stdio.h>
#include <math.h>

double calculate_altitude(double velocity, double distance) {
    double g = 9.81;
    return sqrt(velocity * velocity + 2 * g * distance);
}

double adjust_trajectory(double altitude, double speed) {
    if (altitude > 10000) {
        return speed * 0.95;
    } else {
        return speed * 1.05;
    }
}

int main() {
    double velocity = 300;
    double distance = 10000;
    double altitude = calculate_altitude(velocity, distance);
    double speed = adjust_trajectory(altitude, velocity);
    printf("Adjusted Speed: %f\n", speed);
    return 0;
}