#include <stdio.h>
#include <math.h>

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

void main() {
    double alt = 0;
    double speed = 10;
    double desired_altitude = 30000;
    while (1) {
        alt = update_altitude(alt, speed, 1);
        speed = adjust_speed(speed, desired_altitude, alt);
        if (fabs(alt - desired_altitude) < 100) {
            printf("Cruise altitude reached: %.0f\n", alt);
        } else {
            printf("Current altitude: %.0f\n", alt);
        }
    }
}