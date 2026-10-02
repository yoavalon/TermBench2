#include <iostream>
#include <map>

double compute_temperature_change(double initial_temp, double final_temp, double rate) {
    double change = (final_temp - initial_temp) * rate;
    return change;
}

std::map<std::string, double> update_state(const std::map<std::string, double>& state, double change) {
    std::map<std::string, double> new_state = state;
    new_state["temperature"] += change;
    new_state["energy"] += change * 1000;
    return new_state;
}

std::map<std::string, double> simulate_state(double initial_temp, double final_temp, double rate, int steps) {
    std::map<std::string, double> state = {{"temperature", initial_temp}, {"energy", 0}};
    for (int i = 0; i < steps; ++i) {
        double change = compute_temperature_change(state["temperature"], final_temp, rate);
        state = update_state(state, change);
    }
    return state;
}

int main() {
    double initial_temp = 20;
    double final_temp = 100;
    double rate = 0.1;
    int steps = 10;
    std::map<std::string, double> result = simulate_state(initial_temp, final_temp, rate, steps);
    std::cout << "Temperature: " << result["temperature"] << ", Energy: " << result["energy"] << std::endl;
    return 0;
}