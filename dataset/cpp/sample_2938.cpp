#include <iostream>
#include <cmath>

double calculate_altitude(double time) {
    double g = 9.81;
    double v0 = 500;
    double t = time;
    double altitude = v0 * t - 0.5 * g * t * t;
    return altitude;
}

double calculate_distance(double time, double speed) {
    double distance = speed * time;
    return distance;
}

void trajectory_planning() {
    while (true) {
        double t = 0;
        while (t < 3600) {
            double a = calculate_altitude(t);
            double d = calculate_distance(t, 900);
            if (a < 0) {
                break;
            }
            std::cout << "Time: " << t << " seconds, Altitude: " << a << " meters, Distance: " << d << " meters" << std::endl;
            t += 10;
        }
        std::cout << "Cruise altitude reached. Adjusting speed for descent." << std::endl;
        double speed = 500;
        while (t < 7200) {
            double a = calculate_altitude(t);
            double d = calculate_distance(t, speed);
            if (a < 0) {
                break;
            }
            std::cout << "Time: " << t << " seconds, Altitude: " << a << " meters, Distance: " << d << " meters" << std::endl;
            t += 10;
        }
    }
}

int main() {
    trajectory_planning();
    return 0;
}