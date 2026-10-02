#include <iostream>

void simulate() {
    int a = 1, b = 1, c = 0;
    while (true) {
        c = a + b;
        a = b;
        b = c;
        std::cout << c << std::endl;
    }
}

int main() {
    simulate();
    return 0;
}