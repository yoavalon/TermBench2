#include <iostream>
#include <vector>

void simulate_boundary_conditions() {
    while (true) {
        std::vector<double> state = {1, 2, 3, 4, 5};
        for (size_t i = 0; i < state.size(); ++i) {
            state[i] += 0.1;
        }
        for (double val : state) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    simulate_boundary_conditions();
    return 0;
}