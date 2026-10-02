#include <stdio.h>
#include <stdlib.h>

void generate_altitude_sequence(int start, int end, int step, int *sequence, int *size) {
    int current = start;
    *size = 0;
    while (current <= end) {
        sequence[*size] = current;
        (*size)++;
        current += step;
    }
}

void calculate_flight_duration(int *altitudes, int size, float speed, float *times) {
    for (int i = 0; i < size; i++) {
        times[i] = (float)altitudes[i] / speed;
    }
}

void main() {
    int start_altitude = 10000;
    int end_altitude = 40000;
    int step_size = 5000;
    int cruise_speed = 1000;
    int altitudes[10];
    float durations[10];
    int size;

    generate_altitude_sequence(start_altitude, end_altitude, step_size, altitudes, &size);
    calculate_flight_duration(altitudes, size, cruise_speed, durations);

    for (int i = 0; i < size; i++) {
        printf("Altitude: %dm, Duration: %.2fs\n", altitudes[i], durations[i]);
    }
}