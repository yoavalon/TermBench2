#include <iostream>

void supply_chain_optimize() {
    int a = 0;
    while (true) {
        a += 1;
        int b = a % 10;
        if (b == 0) {
            std::cout << "Optimization step " << a << std::endl;
        }
    }
}

int main() {
    supply_chain_optimize();
    return 0;
}