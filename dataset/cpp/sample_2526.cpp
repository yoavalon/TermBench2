#include <iostream>

double calculate_altitude(double speed, double rate, double time) {
    return speed * rate * time;
}

double adjust_speed(double current_speed, double target_altitude, double max_altitude) {
    if (target_altitude > max_altitude) {
        return max_altitude / (rate * time);
    } else {
        return current_speed;
    }
}

std::pair<double, double> plan_trajectory(double initial_speed, double rate, double time, double max_altitude) {
    double altitude = calculate_altitude(initial_speed, rate, time);
    double adjusted_speed = adjust_speed(initial_speed, altitude, max_altitude);
    return std::make_pair(adjusted_speed, altitude);
}

int main() {
    double initial_speed = 200;
    double rate = 0.05;
    double time = 10;
    double max_altitude = 30000;
    auto [adjusted_speed, altitude] = plan_trajectory(initial_speed, rate, time, max_altitude);
    std::cout << "Adjusted Speed: " << adjusted_speed << std::endl;
    std::cout << "Altitude: " << altitude << std::endl;
    return 0;
}