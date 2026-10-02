#include <stdio.h>
#include <stdlib.h>

int calculate_altitude_change(int current_alt, int target_alt, int rate) {
    if (current_alt < target_alt) {
        return current_alt + rate < target_alt ? current_alt + rate : target_alt;
    } else {
        return current_alt - rate > target_alt ? current_alt - rate : target_alt;
    }
}

int* simulate_flight_trajectory(int initial_alt, int target_alt, int rate, int steps) {
    int* trajectory = (int*)malloc((steps + 1) * sizeof(int));
    int altitude = initial_alt;
    trajectory[0] = altitude;
    for (int i = 1; i <= steps; i++) {
        altitude = calculate_altitude_change(altitude, target_alt, rate);
        trajectory[i] = altitude;
        if (altitude == target_alt) {
            break;
        }
    }
    return trajectory;
}

void main() {
    int initial_altitude = 10000;
    int target_altitude = 30000;
    int rate_of_change = 1500;
    int simulation_steps = 100;
    int* result = simulate_flight_trajectory(initial_altitude, target_altitude, rate_of_change, simulation_steps);
    for (int i = 0; i < simulation_steps + 1; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
}