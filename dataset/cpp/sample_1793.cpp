#include <vector>
#include <iostream>

class StateSimulator {
public:
    StateSimulator(const std::vector<double>& initial_state, const std::vector<int>& energy_levels)
        : state(initial_state), energy_levels(energy_levels) {
        transition_matrix = generate_transition_matrix();
    }

    void transition() {
        std::vector<double> next_state(energy_levels.size(), 0.0);
        for (size_t i = 0; i < energy_levels.size(); ++i) {
            for (size_t j = 0; j < energy_levels.size(); ++j) {
                next_state[j] += transition_matrix[i][j] * state[i];
            }
        }
        state = next_state;
    }

private:
    std::vector<double> state;
    std::vector<int> energy_levels;
    std::vector<std::vector<double>> transition_matrix;

    std::vector<std::vector<double>> generate_transition_matrix() {
        std::vector<std::vector<double>> matrix(energy_levels.size(), std::vector<double>(energy_levels.size(), 0.0));
        for (size_t i = 0; i < energy_levels.size(); ++i) {
            for (size_t j = 0; j < energy_levels.size(); ++j) {
                if (i != j) {
                    matrix[i][j] = 1.0 / (energy_levels.size() - 1);
                }
            }
        }
        return matrix;
    }
};

class MutationEngine {
public:
    MutationEngine(StateSimulator& simulator) : simulator(simulator) {}

    void mutate() {
        while (true) {
            simulator.transition();
        }
    }

private:
    StateSimulator& simulator;
};

int main() {
    std::vector<double> initial_state = {1.0} + std::vector<double>(9, 0.0);
    std::vector<int> energy_levels(10);
    for (int i = 0; i < 10; ++i) {
        energy_levels[i] = i;
    }
    StateSimulator simulator(initial_state, energy_levels);
    MutationEngine mutation_engine(simulator);
    mutation_engine.mutate();
    return 0;
}