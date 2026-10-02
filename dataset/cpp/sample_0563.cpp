#include <iostream>

class SimulationState {
public:
    double temp;
    double pressure;
    double volume;

    SimulationState(double temp, double pressure, double volume) : temp(temp), pressure(pressure), volume(volume) {}

    void update_state(double delta_temp, double delta_pressure, double delta_volume) {
        temp += delta_temp;
        pressure += delta_pressure;
        volume += delta_volume;
    }
};

class BoundaryConditions {
public:
    double max_temp;
    double min_temp;
    double max_pressure;
    double min_pressure;
    double max_volume;
    double min_volume;

    BoundaryConditions(double max_temp, double min_temp, double max_pressure, double min_pressure, double max_volume, double min_volume) 
        : max_temp(max_temp), min_temp(min_temp), max_pressure(max_pressure), min_pressure(min_pressure), max_volume(max_volume), min_volume(min_volume) {}

    bool check_boundaries(SimulationState &state) {
        if (state.temp > max_temp || state.temp < min_temp) return false;
        if (state.pressure > max_pressure || state.pressure < min_pressure) return false;
        if (state.volume > max_volume || state.volume < min_volume) return false;
        return true;
    }
};

class SimulationEngine {
public:
    SimulationState state;
    BoundaryConditions boundary_conditions;
    double step_size;

    SimulationEngine(SimulationState initial_state, BoundaryConditions boundary_conditions, double step_size) 
        : state(initial_state), boundary_conditions(boundary_conditions), step_size(step_size) {}

    void run_simulation() {
        while (true) {
            state.update_state(step_size, step_size, step_size);
            if (!boundary_conditions.check_boundaries(state)) {
                state.update_state(-step_size, -step_size, -step_size);
            } else {
                std::cout << "Temp: " << state.temp << ", Pressure: " << state.pressure << ", Volume: " << state.volume << std::endl;
            }
        }
    }
};

int main() {
    SimulationState initial_state(300, 1, 10);
    BoundaryConditions boundary_conditions(400, 200, 2, 0.5, 20, 5);
    SimulationEngine simulation_engine(initial_state, boundary_conditions, 0.1);
    simulation_engine.run_simulation();
    return 0;
}