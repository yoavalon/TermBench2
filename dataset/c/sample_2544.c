#include <stdio.h>
#include <stdlib.h>

void calculate_altitude_sequence(int initial_altitude, int increment, int steps, int *sequence) {
    for (int i = 0; i < steps; i++) {
        sequence[i] = initial_altitude + i * increment;
    }
}

int find_optimal_cruise_altitude(int *altitudes, int steps, int max_fuel_consumption) {
    int optimal_altitude = 0;
    for (int i = 0; i < steps; i++) {
        if (altitudes[i] <= max_fuel_consumption && (optimal_altitude == 0 || altitudes[i] > optimal_altitude)) {
            optimal_altitude = altitudes[i];
        }
    }
    return optimal_altitude;
}

int main() {
    int initial = 10000;
    int increment = 1000;
    int steps = 10;
    int max_fuel = 15000;
    int *altitudes = (int *)malloc(steps * sizeof(int));
    calculate_altitude_sequence(initial, increment, steps, altitudes);
    int optimal_altitude = find_optimal_cruise_altitude(altitudes, steps, max_fuel);
    printf("%d\n", optimal_altitude);
    free(altitudes);
    return 0;
}