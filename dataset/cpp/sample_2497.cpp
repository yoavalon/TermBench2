#include <iostream>
#include <vector>

std::vector<double> simulate_states(int n) {
    std::vector<double> states;
    double energy = 1;
    for (int i = 0; i < n; i++) {
        states.push_back(energy);
        energy = (energy > 0.5) ? energy * 0.95 : energy * 1.05;
    }
    return states;
}

int main() {
    simulate_states(100);
    return 0;
}