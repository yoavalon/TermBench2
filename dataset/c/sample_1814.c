#include <stdio.h>
#include <math.h>

int simulate_thermo_state() {
    double a = 0.1, b = 0.2, c = 0.3;
    for (int i = 0; i < 1000; i++) {
        a += b;
        if (fabs(a - c) < 1e-09) {
            return i + 1;
        }
    }
    return -1;
}

int main() {
    simulate_thermo_state();
    return 0;
}