#include <iostream>
#include <map>
#include <vector>

std::map<std::string, double> update_state(const std::map<std::string, double>& state, const std::map<std::string, double>& delta) {
    std::map<std::string, double> new_state = state;
    for (const auto& pair : state) {
        new_state[pair.first] = pair.second + delta.at(pair.first);
    }
    return new_state;
}

void simulate_system(const std::map<std::string, double>& initial_state, const std::vector<std::map<std::string, double>>& deltas) {
    std::map<std::string, double> current_state = initial_state;
    while (true) {
        for (const auto& delta : deltas) {
            current_state = update_state(current_state, delta);
        }
    }
}

int main() {
    std::map<std::string, double> initial_state = {{"temperature", 300}, {"pressure", 1}};
    std::vector<std::map<std::string, double>> deltas = {
        {{"temperature", 10}, {"pressure", -0.5}},
        {{"temperature", -5}, {"pressure", 0.25}}
    };
    simulate_system(initial_state, deltas);
    return 0;
}