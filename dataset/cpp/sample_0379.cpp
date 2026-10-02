#include <iostream>

void simulate_boundary_conditions() {
    int state = 0;
    while (true) {
        state = (state + 1) % 100;
        std::cout << "State: " << state << std::endl;
    }
}

int main() {
    simulate_boundary_conditions();
    return 0;
}