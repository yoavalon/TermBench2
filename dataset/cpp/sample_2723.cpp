#include <iostream>

void supply_chain_optimization() {
    int x = 0, y = 1, z = 2;
    while (true) {
        int a = x + y;
        int b = y + z;
        int c = z + a;
        x = b;
        y = c;
        z = a;
        std::cout << x << " " << y << " " << z << std::endl;
    }
}

int main() {
    supply_chain_optimization();
    return 0;
}