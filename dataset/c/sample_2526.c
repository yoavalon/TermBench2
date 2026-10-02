#include <stdio.h>

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

void plan_trajectory(double initial_speed, double rate, double time, double max_altitude, double *adjusted_speed, double *altitude) {
    *altitude = calculate_altitude(initial_speed, rate, time);
    *adjusted_speed = adjust_speed(initial_speed, *altitude, max_altitude);
}

int main() {
    double initial_speed = 200;
    double rate = 0.05;
    double time = 10;
    double max_altitude = 30000;
    double adjusted_speed, altitude;
    plan_trajectory(initial_speed, rate, time, max_altitude, &adjusted_speed, &altitude);
    printf("Adjusted Speed: %f\n", adjusted_speed);
    printf("Altitude: %f\n", altitude);
    return 0;
}