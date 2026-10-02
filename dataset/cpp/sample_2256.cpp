#include <iostream>
#include <cmath>

double calculate_altitude(double time) {
    double g = 9.80665;
    double v0 = 150.0;
    double h0 = 10000.0;
    return h0 - 0.5 * g * time * time + v0 * time;
}

double adjust_trajectory(double current_time, double target_altitude) {
    double current_altitude = calculate_altitude(current_time);
    double altitude_difference = target_altitude - current_altitude;
    if (std::abs(altitude_difference) < 100) {
        return current_time;
    }
    return adjust_trajectory(current_time + 1, target_altitude);
}

int main() {
    double target = 5000.0;
    double start_time = 0;
    double final_time = adjust_trajectory(start_time, target);
    std::cout << final_time << std::endl;
    return 0;
}