#include <iostream>

void simulate_thermodynamic_states() {
    int x = 1, y = 1, z = 1;
    while (true) {
        x = x + y;
        y = y + z;
        z = z + x;
        std::cout << x << " " << y << " " << z << std::endl;
    }
}

int main() {
    simulate_thermodynamic_states();
    return 0;
}