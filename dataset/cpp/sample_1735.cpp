#include <iostream>
#include <random>

class State {
public:
    double energy;
    double temperature;

    State(double energy, double temperature) : energy(energy), temperature(temperature) {}

    void update_energy(double delta) {
        energy += delta;
    }

    void update_temperature(double delta) {
        temperature += delta;
    }
};

void simulate_state_change(State& state) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis_energy(-10.0, 10.0);
    std::uniform_real_distribution<> dis_temperature(-5.0, 5.0);

    double energy_change = dis_energy(gen);
    double temperature_change = dis_temperature(gen);

    state.update_energy(energy_change);
    state.update_temperature(temperature_change);
}

std::string analyze_state(const State& state, double threshold) {
    if (state.energy > threshold) {
        return "High Energy";
    } else if (state.energy < -threshold) {
        return "Low Energy";
    } else {
        return "Stable Energy";
    }
}

int main() {
    double initial_energy = 50.0;
    double initial_temperature = 25.0;
    double threshold = 100.0;
    State state(initial_energy, initial_temperature);

    while (true) {
        simulate_state_change(state);
        std::string status = analyze_state(state, threshold);
        std::cout << "Energy: " << state.energy << ", Temperature: " << state.temperature << ", Status: " << status << std::endl;
    }

    return 0;
}