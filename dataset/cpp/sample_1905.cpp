#include <iostream>
#include <cmath>

double calculate_altitude() {
    double a = 1.0, b = 2.0, c = 3.0;
    double delta = b * b - 4 * a * c;
    if (delta >= 0) {
        return (-b + std::sqrt(delta)) / (2 * a);
    } else {
        return -1; // Using -1 to represent None
    }
}

std::pair<double, double> plan_trajectory() {
    double altitude = calculate_altitude();
    if (altitude != -1) {
        double speed = 0.8 * altitude;
        return std::make_pair(speed, altitude);
    } else {
        return std::make_pair(-1, -1); // Using -1 to represent None
    }
}

int main() {
    auto [speed, altitude] = plan_trajectory();
    if (speed != -1 && altitude != -1) {
        std::cout << "Speed: " << speed << ", Altitude: " << altitude << std::endl;
    } else {
        std::cout << "No valid trajectory." << std::endl;
    }
    return 0;
}