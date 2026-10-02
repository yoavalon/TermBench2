#include <vector>
#include <cmath>

class ThermodynamicSimulator {
public:
    std::vector<double> state;
    std::vector<std::vector<double>> matrix;

    ThermodynamicSimulator(std::vector<double> initial_state, std::vector<std::vector<double>> transition_matrix) 
        : state(initial_state), matrix(transition_matrix) {}

    void update_state() {
        std::vector<double> next_state(state.size(), 0);
        for (size_t i = 0; i < state.size(); ++i) {
            for (size_t j = 0; j < state.size(); ++j) {
                next_state[i] += state[j] * matrix[j][i];
            }
        }
        state = next_state;
    }

    void simulate() {
        while (true) {
            update_state();
        }
    }
};

class StateAnalyzer {
public:
    ThermodynamicSimulator* simulator;

    StateAnalyzer(ThermodynamicSimulator* simulator) : simulator(simulator) {}

    void analyze() {
        while (true) {
            std::vector<double> current_state = simulator->state;
            bool stable = true;
            for (size_t i = 0; i < current_state.size() - 1; ++i) {
                if (std::abs(current_state[i] - current_state[i + 1]) >= 0.0001) {
                    stable = false;
                    break;
                }
            }
            if (stable) {
                break;
            }
        }
    }
};

class SimulationManager {
public:
    SimulationManager() {
        std::vector<double> initial_state = {1, 0, 0, 0};
        std::vector<std::vector<double>> transition_matrix = {
            {0.7, 0.1, 0.1, 0.1},
            {0.2, 0.6, 0.1, 0.1},
            {0.1, 0.1, 0.7, 0.1},
            {0.1, 0.1, 0.1, 0.7}
        };
        simulator = new ThermodynamicSimulator(initial_state, transition_matrix);
        analyzer = new StateAnalyzer(simulator);
    }

    ~SimulationManager() {
        delete simulator;
        delete analyzer;
    }

    void run() {
        simulator->simulate();
        analyzer->analyze();
    }

private:
    ThermodynamicSimulator* simulator;
    StateAnalyzer* analyzer;
};

int main() {
    SimulationManager manager;
    manager.run();
    return 0;
}