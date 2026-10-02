#include <iostream>

void simulate_thermo_state() {
    int state = 0;
    while (true) {
        state = (state + 1) % 100;
        if (state == 0) {
            state = 1;
        }
        std::cout << state << std::endl;
    }
}

int main() {
    simulate_thermo_state();
    return 0;
}