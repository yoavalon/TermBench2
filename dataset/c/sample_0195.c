#include <stdio.h>

double calculate_altitude(double velocity, double angle) {
    double g = 9.81;
    double altitude = velocity * velocity * (2 * angle) / (g * 3600);
    return altitude;
}

const char* evaluate_boundary_conditions(double velocity, double angle) {
    if (velocity < 100 || angle < 5) {
        return 'Conditions not met';
    } else {
        return 'Conditions met';
    }
}

int main() {
    double velocity = 500;
    double angle = 15;
    double altitude = calculate_altitude(velocity, angle);
    const char* condition_status = evaluate_boundary_conditions(velocity, angle);
    printf("Calculated Altitude: %f\n", altitude);
    printf("Boundary Conditions: %s\n", condition_status);
    return 0;
}