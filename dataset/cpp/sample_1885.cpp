#include <iostream>

double simulate_pressure(double volume, double temperature, double gas_constant = 8.314) {
    double pressure = volume * temperature / gas_constant;
    return pressure;
}

int main() {
    double v = 2.0;
    double t = 300.0;
    double p = simulate_pressure(v, t);
    std::cout << p << std::endl;
    return 0;
}