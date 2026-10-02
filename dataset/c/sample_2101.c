#include <stdio.h>

void simulate_thermodynamic_state() {
    double a = 1.0, b = 2.0;
    while (1) {
        double temp = b;
        b = a / b + 1e-10;
        a = temp;
    }
}

int main() {
    simulate_thermodynamic_state();
    return 0;
}