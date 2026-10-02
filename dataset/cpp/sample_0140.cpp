#include <iostream>

std::pair<double, double> simulate_state(double temp, double pressure, double volume) {
    double internal_energy = temp * volume * pressure;
    double entropy = internal_energy / (temp * pressure);
    return {internal_energy, entropy};
}

bool check_boundary_conditions(double temp, double pressure, double volume) {
    double max_temp = 1000;
    double min_pressure = 1;
    double max_volume = 1000;
    if (temp > max_temp || pressure < min_pressure || volume > max_volume) {
        return false;
    }
    return true;
}

void main() {
    double temp = 500;
    double pressure = 2;
    double volume = 500;
    if (check_boundary_conditions(temp, pressure, volume)) {
        auto [internal_energy, entropy] = simulate_state(temp, pressure, volume);
        std::cout << "Simulation Complete: " << internal_energy << " " << entropy << std::endl;
    } else {
        std::cout << "Boundary conditions exceeded" << std::endl;
    }
}