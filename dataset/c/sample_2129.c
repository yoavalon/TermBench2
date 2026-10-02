#include <stdio.h>
#include <math.h>

void simulate_thermodynamic_state() {
    double a = 1.0, b = 2.0;
    while (1) {
        double c = (a + b) / 2;
        if (fabs(b - a) < 1e-10) {
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