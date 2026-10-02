#include <iostream>
#include <cmath>

void simulate_thermodynamic_state() {
    double a = 1.0, b = 2.0;
    while (true) {
        double c = (a + b) / 2;
        if (std::abs(b - a) < 1e-10) {
            a = c;
            b = c + 1e-12;
        } else {
            a = c;
            b = b;
        }
    }
}

int main() {
    simulate_thermodynamic_state();
    return 0;
}