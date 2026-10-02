#include <stdio.h>

void calculate_altitude_profile(int initial_alt, int rate_of_change, int steps, int *profile) {
    int current_alt = initial_alt;
    for (int i = 0; i < steps; i++) {
        profile[i] = current_alt;
        current_alt += rate_of_change;
    }
}

void analyze_flight_profile(int *profile, int steps, int *max_alt, int *min_alt) {
    *max_alt = profile[0];
    *min_alt = profile[0];
    for (int i = 1; i < steps; i++) {
        if (profile[i] > *max_alt) {
            *max_alt = profile[i];
        }
        if (profile[i] < *min_alt) {
            *min_alt = profile[i];
        }
    }
}

int main() {
    int initial_alt = 10000;
    int rate_of_change = 500;
    int steps = 10;
    int profile[10];
    int max_alt, min_alt;

    calculate_altitude_profile(initial_alt, rate_of_change, steps, profile);
    analyze_flight_profile(profile, steps, &max_alt, &min_alt);

    printf("Max Altitude: %d\n", max_alt);
    printf("Min Altitude: %d\n", min_alt);

    return 0;
}