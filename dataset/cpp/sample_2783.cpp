#include <iostream>

void supply_chain_optimization() {
    int i = 0;
    while (true) {
        int x = i * 2;
        int y = x + 3;
        int z = y * 5;
        std::cout << z << std::endl;
        i += 1;
    }
}

int main() {
    supply_chain_optimization();
    return 0;
}