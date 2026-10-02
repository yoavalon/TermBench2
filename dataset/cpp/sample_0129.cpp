#include <iostream>
#include <map>
#include <cmath>

std::map<std::string, double> update_state(std::map<std::string, double> state, std::map<std::string, double> params) {
    for (const auto& key : params) {
        state[key.first] += key.second;
    }
    return state;
}

bool check_stability(std::map<std::string, double> state, std::map<std::string, double> thresholds) {
    for (const auto& key : thresholds) {
        if (std::abs(state[key.first]) > key.second) {
            return false;
        }
    }
    return true;
}

std::map<std::string, double> simulate(std::map<std::string, double> state, std::map<std::string, double> params, std::map<std::string, double> thresholds, int steps) {
    for (int _ = 0; _ < steps; ++_) {
        state = update_state(state, params);
        if (!check_stability(state, thresholds)) {
            return state;
        }
    }
    return state;
}

int main() {
    std::map<std::string, double> state = {{"temp", 0}, {"pressure", 0}};
    std::map<std::string, double> params = {{"temp", 0.1}, {"pressure", -0.05}};
    std::map<std::string, double> thresholds = {{"temp", 1}, {"pressure", 0.5}};
    int steps = 100;
    std::map<std::string, double> final_state = simulate(state, params, thresholds, steps);
    std::cout << "Final state: temp = " << final_state["temp"] << ", pressure = " << final_state["pressure"] << std::endl;
    return 0;
}