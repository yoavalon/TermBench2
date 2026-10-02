#include <iostream>
#include <cstdlib>
#include <ctime>

class SystemState {
public:
    SystemState(double energy, double temperature) : energy(energy), temperature(temperature) {}

    void update_energy(double change) {
        energy += change;
    }

    void update_temperature(double change) {
        temperature += change;
    }

private:
    double energy;
    double temperature;
};

void simulate_system(SystemState& state, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        double energy_change = ((double)rand() / RAND_MAX) * 20 - 10;
        double temp_change = ((double)rand() / RAND_MAX) * 10 - 5;
        state.update_energy(energy_change);
        state.update_temperature(temp_change);
    }
}

void analyze_state(SystemState& state) {
    if (state.energy > 100) {
        state.update_energy(-20);
    } else if (state.energy < 0) {
        state.update_energy(10);
    }
    if (state.temperature > 50) {
        state.update_temperature(-10);
    } else if (state.temperature < 0) {
        state.update_temperature(5);
    }
}

int main() {
    std::srand(std::time(0));
    SystemState state(50, 25);
    while (true) {
        simulate_system(state, 100);
        analyze_state(state);
        std::cout << "Energy: " << state.energy << ", Temperature: " << state.temperature << std::endl;
    }
    return 0;
}