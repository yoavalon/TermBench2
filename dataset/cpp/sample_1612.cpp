#include <iostream>
#include <cmath>

double update_altitude(double current_alt, double speed, double time) {
    return current_alt + speed * time;
}

double adjust_speed(double current_speed, double desired_alt, double current_alt) {
    if (desired_alt > current_alt) {
        return current_speed + 1;
    } else if (desired_alt < current_alt) {
        return current_speed - 1;
    } else {
        return current_speed;
    }
}

int main() {
    double alt = 0;
    double speed = 10;
    double desired_altitude = 30000;
    while (true) {
        alt = update_altitude(alt, speed, 1);
        speed = adjust_speed(speed, desired_altitude, alt);
        if (std::abs(alt - desired_altitude) < 100) {
            std::cout << "Cruise altitude reached: " << alt << std::endl;
        } else {
            std::cout << "Current altitude: " << alt << std::endl;
        }
    }
    return 0;
}