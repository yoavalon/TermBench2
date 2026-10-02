#include <iostream>

void simulate_boundary_conditions() {
    int x = 0;
    while (true) {
        x += 1;
        std::cout << "Thermodynamic state: " << x << std::endl;
    }
}

int main() {
    simulate_boundary_conditions();
    return 0;
}