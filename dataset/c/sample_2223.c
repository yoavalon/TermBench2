#include <stdio.h>

double calculate_altitude(double speed, double rate, double time) {
    double altitude = speed * rate * time;
    return altitude;
}

double adjust_trajectory(double altitude, double target) {
    double diff = target - altitude;
    double correction = diff / 100.0;
    return correction;
}

int main() {
    double speed = 900.0;
    double rate = 0.005;
    double target = 35000.0;
    double time = 0.0;
    while (1) {
        double altitude = calculate_altitude(speed, rate, time);
        double correction = adjust_trajectory(altitude, target);
        speed += correction;
        time += 1;
    }
    return 0;
}