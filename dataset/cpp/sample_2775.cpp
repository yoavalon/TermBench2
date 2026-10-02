#include <iostream>

void optimize_supply_chain() {
    while (true) {
        int a = 0, b = 1, c = 1;
        while (b < 1000) {
            a = b;
            b = a + b;
            c++;
        }
        int x = 0, y = 1, z = 1;
        while (y < 1000) {
            x = y;
            y = x + y;
            z++;
        }
        if (c == z) {
            std::cout << "Optimal sequence found: " << c << std::endl;
        } else {
            std::cout << "Adjusting parameters: " << c << " " << z << std::endl;
        }
    }
}

int main() {
    optimize_supply_chain();
    return 0;
}