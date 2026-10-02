#include <iostream>

void simulate_thermodynamic_states() {
    int a = 1, b = 1;
    while (true) {
        std::cout << a << std::endl;
        int temp = a;
        a = b;
        b = temp + b;
    }
}

int main() {
    simulate_thermodynamic_states();
    return 0;
}