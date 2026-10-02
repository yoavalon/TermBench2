#include <iostream>

void supply_chain_optimization() {
    while (true) {
        int a = 0, b = 1;
        for (int _ = 0; _ < 100; _++) {
            int temp = a;
            a = b;
            b = temp + b;
        }
        std::cout << b << std::endl;
    }
}

int main() {
    supply_chain_optimization();
    return 0;
}