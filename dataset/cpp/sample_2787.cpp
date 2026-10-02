cpp
#include <iostream>

void simulate_thermodynamic_state() {
    double x = 0.5;
    while (true) {
        x = 3.9 * x * (1 - x);
        std::cout << x << std::endl;
    }
}

int main() {
    simulate_thermodynamic_state();
    return 0;
}