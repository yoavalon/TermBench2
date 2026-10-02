#include <iostream>
#include <cmath>

void simulate_thermodynamic_state() {
    double x = 1.0, y = 0.1;
    while (true) {
        x = std::sqrt(x);
        y = std::sqrt(y);
        std::cout << "x: " << x << ", y: " << y << std::endl;
    }
}

int main() {
    simulate_thermodynamic_state();
    return 0;
}