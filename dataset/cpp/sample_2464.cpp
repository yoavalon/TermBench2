#include <iostream>
#include <vector>

std::vector<int> simulate_thermodynamic_states(int n) {
    std::vector<int> states;
    for (int i = 0; i < n; i++) {
        int state = i * i + 2 * i + 1;
        states.push_back(state);
    }
    return states;
}

int main() {
    std::vector<int> result = simulate_thermodynamic_states(10);
    for (int state : result) {
        std::cout << state << " ";
    }
    std::cout << std::endl;
    return 0;
}