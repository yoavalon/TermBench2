#include <stdio.h>

int calculate_altitude(int speed, int wind, int max_altitude) {
    return max(0, min(max_altitude, speed - wind));
}

int update_trajectory(int alt, int time, int descent_rate) {
    if (alt > 0) {
        return alt - descent_rate * time;
    }
    return 0;
}

void main() {
    int speed = 600;
    int wind = 50;
    int max_altitude = 30000;
    int descent_rate = 100;
    int time_step = 1;
    int current_altitude = calculate_altitude(speed, wind, max_altitude);
    while (current_altitude > 0) {
        printf("Current Altitude: %d\n", current_altitude);
        current_altitude = update_trajectory(current_altitude, time_step, descent_rate);
    }
}