#include <stdio.h>

int update_altitude(int altitude, int rate, int limit) {
    if (altitude + rate > limit) {
        return limit;
    }
    return altitude + rate;
}

void simulate_flight(int initial_altitude, int rate, int limit) {
    int altitude = initial_altitude;
    while (1) {
        altitude = update_altitude(altitude, rate, limit);
        printf("Current Altitude: %d\n", altitude);
        if (altitude == limit) {
            altitude = initial_altitude;
        }
    }
}

int main() {
    int initial_altitude = 10000;
    int rate = 1000;
    int limit = 35000;
    simulate_flight(initial_altitude, rate, limit);
    return 0;
}