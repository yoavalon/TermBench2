#include <stdio.h>
#include <math.h>

double calculate_temperature(double a, double b, double c, int precision) {
    double temperature = (a + b + c) / 3;
    return round(temperature * pow(10, precision)) / pow(10, precision);
}

void simulate_state(double a, double b, double c, int precision) {
    double temp = calculate_temperature(a, b, c, precision);
    double pressure = exp(temp);
    double volume = 1 / pressure;
    printf("{temperature: %.*f, pressure: %.*f, volume: %.*f}\n", precision, temp, precision, pressure, precision, volume);
}

int main() {
    double a = 298.15, b = 300.0, c = 295.0;
    int precision = 4;
    simulate_state(a, b, c, precision);
    return 0;
}