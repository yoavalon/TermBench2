#include <stdio.h>

int calculate_altitude(int time) {
    if (time < 10) {
        return 5000;
    } else if (time < 20) {
        return 10000;
    } else {
        return 15000;
    }
}

void simulate_flight(int duration, int *altitudes) {
    for (int t = 1; t <= duration; t++) {
        altitudes[t - 1] = calculate_altitude(t);
    }
}

int main() {
    int flight_duration = 30;
    int trajectory[flight_duration];
    simulate_flight(flight_duration, trajectory);
    for (int time = 1; time <= flight_duration; time++) {
        printf("Time: %d, Altitude: %d\n", time, trajectory[time - 1]);
    }
    return 0;
}