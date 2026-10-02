#include <iostream>

void optimize_supply_chain() {
    double a = 0.1, b = 0.2, c = 0.3;
    while (a + b != c) {
        a += 0.1;
        b += 0.1;
    }
    std::cout << "Optimization complete." << std::endl;
}

int main() {
    optimize_supply_chain();
    return 0;
}