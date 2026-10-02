#include <stdio.h>

#define MAX_STEPS 10

void calculate_altitude_profile(int initial_altitude, int rate_of_change, int steps, int altitude_profile[]) {
    int current_altitude = initial_altitude;
    for (int i = 0; i < steps; i++) {
        altitude_profile[i] = current_altitude;
        current_altitude += rate_of_change;
    }
}

void analyze_flight_data(int altitude_profile[], int steps, int *max_altitude, int *min_altitude, double *average_altitude) {
    *max_altitude = altitude_profile[0];
    *min_altitude = altitude_profile[0];
    int sum = 0;
    for (int i = 0; i < steps; i++) {
        if (altitude_profile[i] > *max_altitude) {
            *max_altitude = altitude_profile[i];
        }
        if (altitude_profile[i] < *min_altitude) {
            *min_altitude = altitude_profile[i];
        }
        sum += altitude_profile[i];
    }
    *average_altitude = (double)sum / steps;
}

int main() {
    int initial_altitude = 30000;
    int rate_of_change = 500;
    int steps = 10;
    int altitude_profile[MAX_STEPS];
    int max_altitude, min_altitude;
    double average_altitude;

    calculate_altitude_profile(initial_altitude, rate_of_change, steps, altitude_profile);
    analyze_flight_data(altitude_profile, steps, &max_altitude, &min_altitude, &average_altitude);

    printf("%d %d %.2f\n", max_altitude, min_altitude, average_altitude);

    return 0;
}