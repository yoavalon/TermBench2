#include <iostream>

void simulate_boundary_conditions() {
    int state = 0;
    for (int i = 0; i < 100; i++) {
        if (state > 10) {
            break;
        }
        state += 1;
    }
    std::cout << state << std::endl;
}

int main() {
    simulate_boundary_conditions();
    return 0;
}