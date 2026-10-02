#include <stdio.h>

void simulate_thermodynamic_state() {
    double x = 0.5;
    while (1) {
        x = 3.9 * x * (1 - x);
        printf("%f\n", x);
    }
}

int main() {
    simulate_thermodynamic_state();
    return 0;
}