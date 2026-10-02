#include <iostream>
#include <vector>

double calculate_cruise_altitude(double speed, double temperature) {
    double a = 1.0287;
    double b = -10.911;
    double c = 260370;
    return a * speed + b * temperature + c;
}

double plan_trajectory(const std::vector<double>& altitudes, double target) {
    double total = 0.0;
    for (double altitude : altitudes) {
        total += altitude;
    }
    double average = total / altitudes.size();
    return average - target;
}

int main() {
    std::vector<double> speeds = {800.5, 900.3, 750.8};
    std::vector<double> temperatures = {15.2, 14.8, 16.0};
    std::vector<double> altitudes;
    for (size_t i = 0; i < speeds.size(); ++i) {
        altitudes.push_back(calculate_cruise_altitude(speeds[i], temperatures[i]));
    }
    double target_altitude = 35000.0;
    double adjustment = plan_trajectory(altitudes, target_altitude);
    std::cout << "Adjustment needed: " << adjustment << " meters" << std::endl;
    return 0;
}