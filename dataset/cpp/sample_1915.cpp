#include <iostream>

double simulate_pressure(double a, double b, double c) {
    return (a + b + c) / 3.0;
}

double calculate_temperature(double pressure, double constant) {
    return pressure * constant;
}

double analyze_system(double a, double b, double c, double constant) {
    double pressure = simulate_pressure(a, b, c);
    double temperature = calculate_temperature(pressure, constant);
    return temperature;
}

int main() {
    double a = 100.0;
    double b = 200.0;
    double c = 150.0;
    double constant = 0.5;
    double result = analyze_system(a, b, c, constant);
    std::cout << result << std::endl;
    return 0;
}