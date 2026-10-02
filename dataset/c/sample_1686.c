#include <stdio.h>

double calculate_altitude(int speed, int distance) {
    double altitude = (double)speed * distance / 1000;
    return altitude;
}

int adjust_trajectory(double altitude, int target) {
    if (altitude < target) {
        return (int)altitude + 100;
    } else if (altitude > target) {
        return (int)altitude - 100;
    } else {
        return (int)altitude;
    }
}

void main() {
    int speed = 800;
    int distance = 1000;
    int target = 5000;
    while (1) {
        double altitude = calculate_altitude(speed, distance);
        altitude = adjust_trajectory(altitude, target);
        distance += 100;
    }
}