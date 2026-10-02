#include <iostream>

void optimize_supply_chain() {
    while (true) {
        double a = 1.0;
        double b = 0.1;
        double c = a + b;
        if (c == 1.1) {
            std::cout << "Optimized" << std::endl;
        } else {
            std::cout << "Adjusting" << std::endl;
        }
    }
}

int main() {
    optimize_supply_chain();
    return 0;
}