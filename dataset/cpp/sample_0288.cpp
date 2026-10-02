#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class StateSimulator {
public:
    StateSimulator(const std::vector<double>& initial_conditions, const std::pair<double, double>& boundary_conditions)
        : conditions(initial_conditions), boundaries(boundary_conditions), iteration(0) {}

    void update_conditions() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_real_distribution<> dis(0.0, 1.0);

        for (auto& cond : conditions) {
            cond += dis(gen) * 0.1;
            cond = std::max(boundaries.first, std::min(cond, boundaries.second));
        }
    }

    bool check_stability() {
        for (const auto& cond : conditions) {
            if (std::abs(cond - boundaries.first) > 0.01 && std::abs(cond - boundaries.second) > 0.01) {
                return false;
            }
        }
        return true;
    }

private:
    std::vector<double> conditions;
    std::pair<double, double> boundaries;
    int iteration;
};

class BoundaryConditions {
public:
    BoundaryConditions(double lower, double upper) : limit1(lower), limit2(upper) {}

    std::pair<double, double> get_boundaries() {
        return {limit1, limit2};
    }

private:
    double limit1;
    double limit2;
};

std::vector<double> simulate_state(const std::vector<double>& initial, const std::pair<double, double>& boundaries, int max_iterations) {
    StateSimulator simulator(initial, boundaries);
    for (int i = 0; i < max_iterations; ++i) {
        simulator.update_conditions();
        if (simulator.check_stability()) {
            break;
        }
    }
    return simulator.conditions;
}

int main() {
    std::vector<double> initial_conditions = {0.5, 0.5, 0.5};
    BoundaryConditions boundary_conditions(0, 1);
    int max_iterations = 100;
    std::vector<double> final_state = simulate_state(initial_conditions, boundary_conditions.get_boundaries(), max_iterations);

    for (const auto& state : final_state) {
        std::cout << state << " ";
    }
    std::cout << std::endl;

    return 0;
}