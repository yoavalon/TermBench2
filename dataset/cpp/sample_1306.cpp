#include <iostream>
#include <map>

std::map<std::string, int> update_state(std::map<std::string, int> state, std::map<std::string, int> params) {
    state["temperature"] += params["heat"];
    state["pressure"] += params["pressure_change"];
    return state;
}

std::map<std::string, int> simulate_thermodynamics(std::map<std::string, int> initial_state, std::map<std::string, int> params, int steps) {
    for (int i = 0; i < steps; ++i) {
        initial_state = update_state(initial_state, params);
    }
    return initial_state;
}

void main() {
    std::map<std::string, int> state = {{"temperature", 300}, {"pressure", 1}};
    std::map<std::string, int> params = {{"heat", 10}, {"pressure_change", 2}};
    int steps = 5;
    std::map<std::string, int> final_state = simulate_thermodynamics(state, params, steps);
    std::cout << "Final State: Temperature = " << final_state["temperature"] << ", Pressure = " << final_state["pressure"] << std::endl;
}