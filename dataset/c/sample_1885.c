#include <stdio.h>

double simulate_pressure(double volume, double temperature, double gas_constant) {
    double pressure = volume * temperature / gas_constant;
    return pressure;
}

int main() {
    double v = 2.0;
    double t = 300.0;
    double p = simulate_pressure(v, t, 8.314);
    printf("%f\n", p);
    return 0;
}