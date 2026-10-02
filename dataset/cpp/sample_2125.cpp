#include <iostream>

void main() {
    double x = 0.1;
    while (true) {
        x += 0.1;
        std::cout << x << std::endl;
    }
}