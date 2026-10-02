#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void simulate_thermodynamic_state() {
    double x = (double)rand() / RAND_MAX;
    while (x > 0.0001) {
        double y = sin(x) + cos(x);
        double z = exp(-x);
        x = y * z;
    }
}

int main() {
    simulate_thermodynamic_state();
    return 0;
}