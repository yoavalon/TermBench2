#include <stdio.h>
#include <math.h>

void calculate_trajectory(double velocity, double altitude, double time, double *distance, double *new_altitude) {
    double gravity = 9.81;
    *distance = velocity * time;
    double altitude_change = velocity * time - 0.5 * gravity * time * time;
    *new_altitude = altitude + altitude_change;
}

double plan_cruise_altitude(double initial_altitude, double max_altitude, double rate_of_climb, double time) {
    if (initial_altitude < max_altitude) {
        double new_altitude = initial_altitude + rate_of_climb * time;
        return fmin(new_altitude, max_altitude);
    }
    return initial_altitude;
}

int main() {
    double velocity = 250;
    double altitude = 5000;
    double time = 3600;
    double max_altitude = 10000;
    double rate_of_climb = 500;
    double distance, new_altitude;
    calculate_trajectory(velocity, altitude, time, &distance, &new_altitude);
    double cruise_altitude = plan_cruise_altitude(new_altitude, max_altitude, rate_of_climb, time);
    printf("Distance covered: %f meters\n", distance);
    printf("New altitude: %f meters\n", new_altitude);
    printf("Cruise altitude: %f meters\n", cruise_altitude);
    return 0;
}