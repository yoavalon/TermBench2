#include <iostream>

void simulate_thermodynamics() {
    double a = 0.5;
    double b = 1.0;
    while (true) {
        double c = a * b;
        a += 0.01;
        b -= 0.01;
    }
}

int main() {
    simulate_thermodynamics();
    return 0;
}