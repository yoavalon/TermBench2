#include <iostream>
#include <vector>

class SystemState {
public:
    double temp;
    double pressure;
    double volume;

    SystemState(double temp, double pressure, double volume) : temp(temp), pressure(pressure), volume(volume) {}

    void update(double temp_change, double pressure_change, double volume_change) {
        temp += temp_change;
        pressure += pressure_change;
        volume += volume_change;
    }
};

class Simulation {
public:
    SystemState state;
    std::vector<std::function<void(SystemState&)>> conditions;

    Simulation(SystemState initial_state) : state(initial_state) {}

    void add_condition(std::function<void(SystemState&)> condition) {
        conditions.push_back(condition);
    }

    void run() {
        while (true) {
            for (auto& condition : conditions) {
                condition(state);
            }
        }
    }
};

class BoundaryCondition {
public:
    double threshold;
    std::function<void(SystemState&)> effect;

    BoundaryCondition(double threshold, std::function<void(SystemState&)> effect) : threshold(threshold), effect(effect) {}

    void operator()(SystemState& state) {
        if (state.temp > threshold) {
            effect(state);
        }
    }
};

void apply_effect(SystemState& state) {
    state.update(-10, 5, -2);
}

void main() {
    SystemState initial_state(300, 101325, 0.5);
    Simulation simulation(initial_state);
    BoundaryCondition condition(350, apply_effect);
    simulation.add_condition(condition);
    simulation.run();
}