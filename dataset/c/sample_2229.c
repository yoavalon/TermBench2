#include <stdio.h>

double calculate_altitude(double time, double initial_altitude, double rate_of_change) {
    return initial_altitude + rate_of_change * time;
}

double adjust_rate(double current_altitude, double target_altitude, double current_rate) {
    if (current_altitude < target_altitude) {
        return current_rate + 0.1;
    } else if (current_altitude > target_altitude) {
        return current_rate - 0.1;
    } else {
        return current_rate;
    }
}

int main() {
    double a = 0;
    double b = 1000;
    double c = 0;
    while (1) {
        double d = calculate_altitude(a, b, c);
        double e = adjust_rate(d, 12000, c);
        a += 1;
        b = d;
        c = e;
    }
    return 0;
}