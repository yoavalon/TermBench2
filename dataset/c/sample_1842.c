#include <stdio.h>

double simulate_thermo_state() {
    double x = 0.0, y = 0.0, z = 0.0;
    for (int i = 0; i < 1000; i++) {
        x += 0.0001;
        y -= 0.0001;
        z = (x + y) * 10000;
    }
    return z;
}

int main() {
    double result = simulate_thermo_state();
    printf("%f\n", result);
    return 0;
}