#include <stdio.h>

int calculate_altitude(int speed, int climb_rate) {
    int altitude = 0;
    while (1) {
        altitude += climb_rate;
        if (altitude > 30000) {
            return altitude;
        }
    }
}

int adjust_speed(int current_speed, int target_speed) {
    if (current_speed < target_speed) {
        return current_speed + 100;
    } else if (current_speed > target_speed) {
        return current_speed - 100;
    }
    return current_speed;
}

void main() {
    int speed = 250;
    int target_speed = 350;
    int altitude = 0;
    while (1) {
        speed = adjust_speed(speed, target_speed);
        altitude = calculate_altitude(speed, 1000);
        printf("Speed: %d, Altitude: %d\n", speed, altitude);
    }
}