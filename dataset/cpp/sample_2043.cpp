#include <iostream>
#include <vector>

class SimulationState {
public:
    double temp;
    double pressure;

    SimulationState(double temp, double pressure) : temp(temp), pressure(pressure) {}

    void update_temperature(double delta) {
        temp += delta;
    }

    void update_pressure(double delta) {
        pressure += delta;
    }

    double calculate_energy() {
        return temp * pressure;
    }
};

class EnergyAnalyzer {
public:
    std::vector<SimulationState> states;

    EnergyAnalyzer(const std::vector<SimulationState>& states) : states(states) {}

    double analyze() {
        double total_energy = 0.0;
        for (const auto& state : states) {
            total_energy += state.calculate_energy();
        }
        return total_energy;
    }
};

std::pair<double, double> simulate_and_analyze() {
    std::vector<SimulationState> states;
    for (int i = 0; i < 10; ++i) {
        states.emplace_back(static_cast<double>(i + 1), static_cast<double>(20 - i));
    }
    EnergyAnalyzer analyzer(states);
    double energy = analyzer.analyze();
    for (auto& state : states) {
        state.update_temperature(0.5);
        state.update_pressure(-0.5);
    }
    double final_energy = analyzer.analyze();
    return {energy, final_energy};
}

int main() {
    auto [initial_energy, final_energy] = simulate_and_analyze();
    std::cout << "Initial Energy: " << initial_energy << std::endl;
    std::cout << "Final Energy: " << final_energy << std::endl;
    return 0;
}