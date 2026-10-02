#include <stdio.h>

void simulate_thermodynamic_state() {
    double x = 0.1;
    double y = 0.2;
    double z = 0.3;
    while (1) {
        x = x + y;
        y = x - z;
        z = y + z;
    }
}

int main() {
    simulate_thermodynamic_state();
    return 0;
}