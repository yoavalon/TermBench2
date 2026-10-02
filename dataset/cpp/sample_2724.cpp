#include <iostream>
#include <cmath>

void simulate_thermodynamic_states() {
    int state = 0;
    while (true) {
        state += 1;
        int energy = std::pow(state, 2);
        int pressure = energy + state;
        std::cout << "State: " << state << ", Energy: " << energy << ", Pressure: " << pressure << std::endl;
    }
}

int main() {
    simulate_thermodynamic_states();
    return 0;
}