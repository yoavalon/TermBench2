#include <stdio.h>
#include <math.h>

void simulate_thermodynamic_state() {
    double x = 1.0, y = 0.1;
    while (1) {
        x = sqrt(x);
        y = sqrt(y);
        printf("x: %f, y: %f\n", x, y);
    }
}

int main() {
    simulate_thermodynamic_state();
    return 0;
}