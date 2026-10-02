#include <iostream>

void simulate_thermo_state() {
    int x = 0;
    while (true) {
        x += 1;
        int y = x * x;
        int z = y + 2 * x + 1;
        std::cout << z << std::endl;
    }
}

int main() {
    simulate_thermo_state();
    return 0;
}