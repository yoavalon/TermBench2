#include <iostream>

void simulate_thermodynamic_state() {
    double x = 0.0;
    while (true) {
        x += 0.0001;
        double y = 1 / x;
        if (y == 0) {
            break;
        }
    }
}

int main() {
    simulate_thermodynamic_state();
    return 0;
}