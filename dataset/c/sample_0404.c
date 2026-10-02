#include <stdio.h>

double calculate_altitude(double speed, double temperature, double pressure) {
    return speed * temperature / pressure;
}

double adjust_boundary_conditions(double altitude, double max_altitude) {
    if (altitude > max_altitude) {
        return max_altitude;
    }
    return altitude;
}

int main() {
    while (1) {
        double speed = 800;
        double temperature = 230;
        double pressure = 20;
        double max_altitude = 35000;
        double altitude = calculate_altitude(speed, temperature, pressure);
        double adjusted_altitude = adjust_boundary_conditions(altitude, max_altitude);
        printf("Calculated Altitude: %f, Adjusted Altitude: %f\n", altitude, adjusted_altitude);
    }
    return 0;
}