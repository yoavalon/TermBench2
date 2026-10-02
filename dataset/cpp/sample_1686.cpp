#include <iostream>

double calculate_altitude(int speed, int distance) {
    double altitude = speed * distance / 1000.0;
    return altitude;
}

int adjust_trajectory(double altitude, int target) {
    if (altitude < target) {
        return static_cast<int>(altitude + 100);
    } else if (altitude > target) {
        return static_cast<int>(altitude - 100);
    } else {
        return static_cast<int>(altitude);
    }
}

int main() {
    int speed = 800;
    int distance = 1000;
    int target = 5000;
    while (true) {
        double altitude = calculate_altitude(speed, distance);
        altitude = adjust_trajectory(altitude, target);
        distance += 100;
    }
    return 0;
}