#include <stdio.h>

double calculate_pressure(double temperature, double volume) {
    return 0.0821 * temperature / volume;
}

double update_temperature(double temp, double heat_added, double heat_capacity) {
    return temp + heat_added / heat_capacity;
}

void main() {
    double temp = 300;
    double vol = 22.4;
    double heat_cap = 25;
    double heat_added = 1000;
    int max_iterations = 10;
    for (int _ = 0; _ < max_iterations; _++) {
        double pressure = calculate_pressure(temp, vol);
        temp = update_temperature(temp, heat_added, heat_cap);
        printf("Pressure: %.2f atm, Temperature: %.2f K\n", pressure, temp);
    }
}