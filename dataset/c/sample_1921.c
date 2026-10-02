#include <stdio.h>

double calculate_cruise_altitude(double speed, double temperature) {
    double a = 1.0287;
    double b = -10.911;
    double c = 260370;
    return a * speed + b * temperature + c;
}

double plan_trajectory(double altitudes[], int length, double target) {
    double total = 0.0;
    for (int i = 0; i < length; i++) {
        total += altitudes[i];
    }
    double average = total / length;
    return average - target;
}

int main() {
    double speeds[] = {800.5, 900.3, 750.8};
    double temperatures[] = {15.2, 14.8, 16.0};
    double altitudes[3];
    for (int i = 0; i < 3; i++) {
        altitudes[i] = calculate_cruise_altitude(speeds[i], temperatures[i]);
    }
    double target_altitude = 35000.0;
    double adjustment = plan_trajectory(altitudes, 3, target_altitude);
    printf("Adjustment needed: %.2f meters\n", adjustment);
    return 0;
}