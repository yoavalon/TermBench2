#include <iostream>

void simulate_thermodynamic_state() {
    double a = 1.0, b = 2.0;
    while (true) {
        double temp = a;
        a = b;
        b = temp / b + 1e-10;
    }
}

int main() {
    simulate_thermodynamic_state();
    return 0;
}