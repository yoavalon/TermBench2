#include <stdio.h>

double compute_temperature_change(double temperature, double heat, double mass, double specific_heat) {
    return temperature + heat / (mass * specific_heat);
}

double update_boundary_conditions(double temperature, double boundary, double threshold) {
    if (temperature > threshold) {
        return boundary - 0.1;
    }
    return boundary + 0.1;
}

void simulate_system() {
    double t = 300.0;
    double b = 1.0;
    double m = 10.0;
    double c = 0.5;
    double h = 100.0;
    double threshold = 350.0;
    while (1) {
        t = compute_temperature_change(t, h, m, c);
        b = update_boundary_conditions(t, b, threshold);
    }
}

int main() {
    simulate_system();
    return 0;
}