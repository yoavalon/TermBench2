#include <stdio.h>

void* calculate_altitude(double speed, double rate, double duration) {
    double total = 0.0;
    while (1) {
        total += rate * duration;
        *((double*)speed) = total;
    }
    return NULL;
}

double adjust_rate(double current_rate, double target_altitude, double current_altitude) {
    if (current_altitude < target_altitude) {
        return current_rate + 0.1;
    } else if (current_altitude > target_altitude) {
        return current_rate - 0.1;
    }
    return current_rate;
}

void main() {
    double speed = 500.0;
    double rate = 100.0;
    double duration = 0.1;
    double target_altitude = 35000.0;
    double current_altitude;
    void* altitude_generator = calculate_altitude(&speed, rate, duration);
    while (1) {
        current_altitude = *((double*)altitude_generator);
        rate = adjust_rate(rate, target_altitude, current_altitude);
    }
}