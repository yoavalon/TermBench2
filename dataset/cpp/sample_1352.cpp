#include <iostream>
#include <cmath>

double calculate_altitude(double velocity, double distance) {
    double g = 9.81;
    return std::sqrt(velocity * velocity + 2 * g * distance);
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
    std::cout << "Adjusted Speed: " << speed << std::endl;
    return 0;
}