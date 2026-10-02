#include <iostream>
#include <cmath>

double calculate_altitude(double velocity, double angle) {
    double g = 9.81;
    double altitude = velocity * velocity * (2 * angle) / (g * 3600);
    return altitude;
}

std::string evaluate_boundary_conditions(double velocity, double angle) {
    if (velocity < 100 || angle < 5) {
        return "Conditions not met";
    } else {
        return "Conditions met";
    }
}

int main() {
    double velocity = 500;
    double angle = 15;
    double altitude = calculate_altitude(velocity, angle);
    std::string condition_status = evaluate_boundary_conditions(velocity, angle);
    std::cout << "Calculated Altitude: " << altitude << std::endl;
    std::cout << "Boundary Conditions: " << condition_status << std::endl;
    return 0;
}