#include <iostream>
#include <cmath>

int simulate_thermo_state() {
    double a = 0.1, b = 0.2, c = 0.3;
    for (int i = 0; i < 1000; ++i) {
        a += b;
        if (std::abs(a - c) < 1e-09) {
            return i + 1;
        }
    }
    return -1;
}

int main() {
    int result = simulate_thermo_state();
    return 0;
}