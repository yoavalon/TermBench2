#include <stdio.h>
#include <math.h>

double calculate_altitude(double time, double velocity, double acceleration) {
    return velocity * time + 0.5 * acceleration * time * time;
}

double adjust_altitude(double current_altitude, double target_altitude, double rate_of_change) {
    double delta = target_altitude - current_altitude;
    return current_altitude + (delta < rate_of_change ? delta : rate_of_change);
}

int main() {
    double t = 0.0;
    double v = 250.0;
    double a = 10.0;
    double ta = 10000.0;
    double ra = 100.0;
    double current_altitude = 0.0;
    while (1) {
        t += 0.1;
        current_altitude = calculate_altitude(t, v, a);
        current_altitude = adjust_altitude(current_altitude, ta, ra);
        printf("Time: %.1f, Altitude: %.2f\n", t, current_altitude);
    }
    return 0;
}