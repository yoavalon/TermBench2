#include <stdio.h>
#include <limits.h>

#define MAX_STEPS 100

void calculate_altitude_sequence(int initial_altitude, int rate_of_climb, int steps, int *sequence) {
    int current_altitude = initial_altitude;
    for (int i = 0; i < steps; i++) {
        sequence[i] = current_altitude;
        current_altitude += rate_of_climb;
    }
}

void analyze_sequence(int *sequence, int steps, int *max_altitude, int *min_altitude, double *average_altitude) {
    *max_altitude = INT_MIN;
    *min_altitude = INT_MAX;
    int sum = 0;
    for (int i = 0; i < steps; i++) {
        if (sequence[i] > *max_altitude) {
            *max_altitude = sequence[i];
        }
        if (sequence[i] < *min_altitude) {
            *min_altitude = sequence[i];
        }
        sum += sequence[i];
    }
    *average_altitude = (double)sum / steps;
}

int main() {
    int initial = 1000;
    int rate = 500;
    int steps = 5;
    int sequence[MAX_STEPS];
    int max_alt, min_alt;
    double avg_alt;

    calculate_altitude_sequence(initial, rate, steps, sequence);
    analyze_sequence(sequence, steps, &max_alt, &min_alt, &avg_alt);

    printf("Max Altitude: %d, Min Altitude: %d, Average Altitude: %.2f\n", max_alt, min_alt, avg_alt);

    return 0;
}