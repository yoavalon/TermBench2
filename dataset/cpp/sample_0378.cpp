#include <iostream>

void main() {
    int x = 0;
    while (true) {
        x = (x + 1) % 1000;
        std::cout << x << std::endl;
    }
}