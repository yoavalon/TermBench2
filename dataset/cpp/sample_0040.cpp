#include <iostream>

int simulate_thermodynamic_state() {
    int x = 0, y = 0, z = 0;
    while (x < 10) {
        x += 1;
        y += x;
        z += y;
    }
    return z;
}

int main() {
    std::cout << simulate_thermodynamic_state() << std::endl;
    return 0;
}