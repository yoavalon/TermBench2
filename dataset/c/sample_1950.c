#include <stdio.h>
#include <math.h>

double calculate_altitude(double distance, double speed, double time) {
    return distance / (speed * time);
}

double adjust_precision(double altitude, int precision) {
    double factor = pow(10, precision);
    return round(altitude * factor) / factor;
}

void main() {
    double dist = 1200.5;
    double spd = 300.25;
    double t = 2.0;
    int precision = 2;
    double alt = calculate_altitude(dist, spd, t);
    double adjusted_alt = adjust_precision(alt, precision);
    printf("Cruise Altitude: %f\n", adjusted_alt);
}