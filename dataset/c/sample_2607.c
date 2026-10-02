#include <stdio.h>
#include <stdlib.h>

void calculate_altitude_profile(int distance, int speed, int rate_of_climb, int cruise_altitude, int descent_rate, int **times, int **altitudes, int *size) {
    *size = distance / speed;
    *times = (int *)malloc(*size * sizeof(int));
    *altitudes = (int *)malloc(*size * sizeof(int));
    int current_time = 0;
    int current_altitude = 0;
    for (int i = 0; i < *size; i++) {
        if (current_altitude < rate_of_climb * current_time) {
            current_altitude = rate_of_climb * current_time;
        } else if (current_altitude < cruise_altitude) {
            current_altitude = cruise_altitude;
        } else {
            current_altitude -= descent_rate * (current_time - cruise_altitude / rate_of_climb);
        }
        (*times)[i] = current_time;
        (*altitudes)[i] = current_altitude;
        current_time += 1;
    }
}

void analyze_flight_profile(int *times, int *altitudes, int size, int *max_altitude, int *cruise_start_time, int *descent_start_time) {
    *max_altitude = altitudes[0];
    for (int i = 1; i < size; i++) {
        if (altitudes[i] > *max_altitude) {
            *max_altitude = altitudes[i];
        }
    }
    for (int i = 0; i < size; i++) {
        if (altitudes[i] == cruise_altitude) {
            *cruise_start_time = times[i];
            break;
        }
    }
    *descent_start_time = times[size - 1];
}

void main() {
    int distance = 1000;
    int speed = 800;
    int rate_of_climb = 100;
    int cruise_altitude = 10000;
    int descent_rate = 50;
    int *times;
    int *altitudes;
    int size;
    calculate_altitude_profile(distance, speed, rate_of_climb, cruise_altitude, descent_rate, &times, &altitudes, &size);
    int max_altitude;
    int cruise_start_time;
    int descent_start_time;
    analyze_flight_profile(times, altitudes, size, &max_altitude, &cruise_start_time, &descent_start_time);
    printf("Maximum Altitude: %d meters\n", max_altitude);
    printf("Cruise Start Time: %d seconds\n", cruise_start_time);
    printf("Descent Start Time: %d seconds\n", descent_start_time);
    free(times);
    free(altitudes);
}