#include <iostream>
#include <map>

std::map<std::string, double> initialize_system() {
    std::map<std::string, double> state;
    state["temperature"] = 300;
    state["pressure"] = 1;
    state["energy"] = 500;
    return state;
}

std::map<std::string, double> update_state(std::map<std::string, double> state, double time_step) {
    state["temperature"] += 0.1 * time_step;
    state["pressure"] += 0.01 * time_step;
    state["energy"] -= 10 * time_step;
    return state;
}

bool check_termination(std::map<std::string, double> state) {
    return state["energy"] <= 0;
}

std::map<std::string, double> simulate() {
    std::map<std::string, double> state = initialize_system();
    double time_step = 1;
    while (!check_termination(state)) {
        state = update_state(state, time_step);
    }
    return state;
}

void main() {
    std::map<std::string, double> final_state = simulate();
    std::cout << "Final State: ";
    for (const auto& pair : final_state) {
        std::cout << pair.first << ": " << pair.second << ", ";
    }
    std::cout << std::endl;
}