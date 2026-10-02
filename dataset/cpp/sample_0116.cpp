#include <iostream>
#include <map>

double calculate_energy(const std::map<std::string, double>& state, const std::map<std::string, double>& boundary) {
    double energy = 0;
    for (const auto& key : state) {
        energy += state.at(key.first) * boundary.at(key.first);
    }
    return energy;
}

bool check_condition(double energy, double threshold) {
    if (energy > threshold) {
        return true;
    }
    return false;
}

int main() {
    std::map<std::string, double> state = {{"temperature", 300}, {"pressure", 101325}, {"volume", 0.0224}};
    std::map<std::string, double> boundary = {{"temperature", 0.001}, {"pressure", -0.0001}, {"volume", 0.001}};
    double threshold = 500;
    double energy = calculate_energy(state, boundary);
    bool condition_met = check_condition(energy, threshold);
    if (condition_met) {
        std::cout << "Condition met: " << energy << std::endl;
    } else {
        std::cout << "Condition not met: " << energy << std::endl;
    }
    return 0;
}