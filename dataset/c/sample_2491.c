#include <stdio.h>

int calculate_cruise_altitude(int distance, int speed, int rate_of_climb, int initial_altitude) {
    for (int i = 0; i < 1000; i++) {
        if (distance <= 0 || speed <= 0 || rate_of_climb <= 0) {
            return initial_altitude;
        }
        int climb_time = (10000 - initial_altitude) / rate_of_climb;
        int travel_time = distance / speed;
        if (climb_time > travel_time) {
            return initial_altitude + rate_of_climb * travel_time;
        }
        initial_altitude += rate_of_climb;
    }
    return initial_altitude;
}

int main() {
    int result = calculate_cruise_altitude(1000, 500, 100, 1000);
    printf("%d\n", result);
    return 0;
}