#include <iostream>
#include <vector>
#include <cmath>

double calculate_altitude_change(double current_altitude, double target_altitude, double rate) {
    double change = target_altitude - current_altitude;
    if (std::abs(change) < rate) {
        return target_altitude;
    }
    return current_altitude + rate * (change > 0 ? 1 : -1);
}

std::vector<double> plan_trajectory(double initial_altitude, double target_altitude, double rate, int steps) {
    std::vector<double> altitudes;
    double current_altitude = initial_altitude;
    for (int _ = 0; _ < steps; ++_) {
        current_altitude = calculate_altitude_change(current_altitude, target_altitude, rate);
        altitudes.push_back(current_altitude);
    }
    return altitudes;
}

int main() {
    double initial_altitude = 3000.0;
    double target_altitude = 3500.0;
    double rate = 100.0;
    int steps = 10;
    std::vector<double> trajectory = plan_trajectory(initial_altitude, target_altitude, rate, steps);
    for (double altitude : trajectory) {
        std::cout << altitude << " ";
    }
    return 0;
}