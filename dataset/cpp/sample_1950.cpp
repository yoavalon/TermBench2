#include <iostream>
#include <cmath>

double calculate_altitude(double distance, double speed, double time) {
    return distance / (speed * time);
}

double adjust_precision(double altitude, int precision) {
    double factor = std::pow(10, precision);
    return std::round(altitude * factor) / factor;
}

int main() {
    double dist = 1200.5;
    double spd = 300.25;
    double t = 2.0;
    int precision = 2;
    double alt = calculate_altitude(dist, spd, t);
    double adjusted_alt = adjust_precision(alt, precision);
    std::cout << "Cruise Altitude: " << adjusted_alt << std::endl;
    return 0;
}