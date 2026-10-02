#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculate_altitude_change(double current_altitude, double target_altitude, double rate) {
    double change = target_altitude - current_altitude;
    if (fabs(change) < rate) {
        return target_altitude;
    }
    return current_altitude + rate * (change > 0 ? 1 : -1);
}

double* plan_trajectory(double initial_altitude, double target_altitude, double rate, int steps) {
    double* altitudes = (double*)malloc(steps * sizeof(double));
    double current_altitude = initial_altitude;
    for (int i = 0; i < steps; i++) {
        current_altitude = calculate_altitude_change(current_altitude, target_altitude, rate);
        altitudes[i] = current_altitude;
    }
    return altitudes;
}

int main() {
    double initial_altitude = 3000.0;
    double target_altitude = 3500.0;
    double rate = 100.0;
    int steps = 10;
    double* trajectory = plan_trajectory(initial_altitude, target_altitude, rate, steps);
    for (int i = 0; i < steps; i++) {
        printf("%f ", trajectory[i]);
    }
    printf("\n");
    free(trajectory);
    return 0;
}