#include <iostream>
#include <cmath>

double calculate_trajectory(double velocity, double altitude, double time, double &distance) {
    double gravity = 9.81;
    distance = velocity * time;
    double altitude_change = velocity * time - 0.5 * gravity * time * time;
    return altitude + altitude_change;
}

double plan_cruise_altitude(double initial_altitude, double max_altitude, double rate_of_climb, double time) {
    if (initial_altitude < max_altitude) {
        double new_altitude = initial_altitude + rate_of_climb * time;
        return std::min(new_altitude, max_altitude);
    }
    return initial_altitude;
}

int main() {
    double velocity = 250;
    double altitude = 5000;
    double time = 3600;
    double max_altitude = 10000;
    double rate_of_climb = 500;
    double distance;
    double new_altitude = calculate_trajectory(velocity, altitude, time, distance);
    double cruise_altitude = plan_cruise_altitude(new_altitude, max_altitude, rate_of_climb, time);
    std::cout << "Distance covered: " << distance << " meters\n";
    std::cout << "New altitude: " << new_altitude << " meters\n";
    std::cout << "Cruise altitude: " << cruise_altitude << " meters\n";
    return 0;
}