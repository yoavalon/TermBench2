#include <iostream>
#include <vector>
#include <cmath>

class ThermodynamicState {
public:
    double temp;
    double pressure;

    ThermodynamicState(double temp, double pressure) : temp(temp), pressure(pressure) {}

    void update_state(double temp_change, double pressure_change) {
        temp += temp_change;
        pressure += pressure_change;
    }

    double calculate_entropy() {
        if (temp <= 0) {
            return std::numeric_limits<double>::quiet_NaN();
        }
        return pressure / temp;
    }
};

class SimulationController {
public:
    ThermodynamicState state;
    int iterations;
    std::vector<double> data;

    SimulationController(ThermodynamicState initial_state, int iterations) : state(initial_state), iterations(iterations) {}

    void run_simulation() {
        for (int i = 0; i < iterations; ++i) {
            state.update_state(0.1, -0.05);
            data.push_back(state.calculate_entropy());
        }
    }

    std::vector<double> get_results() {
        return data;
    }
};

double analyze_data(const std::vector<double>& data) {
    double total = 0;
    int count = 0;
    for (double value : data) {
        if (!std::isnan(value)) {
            total += value;
            count += 1;
        }
    }
    return count > 0 ? total / count : std::numeric_limits<double>::quiet_NaN();
}

int main() {
    ThermodynamicState initial_state(300, 100);
    SimulationController controller(initial_state, 50);
    controller.run_simulation();
    std::vector<double> results = controller.get_results();
    double average_entropy = analyze_data(results);
    std::cout << "Average Entropy: " << average_entropy << std::endl;
    return 0;
}