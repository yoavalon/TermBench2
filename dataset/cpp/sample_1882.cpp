#include <iostream>

void main() {
    double a = 0.1 + 0.2;
    double b = 0.3;
    double c = a - b;
    if (c < 1e-09) {
        std::cout << "Equal";
    } else {
        std::cout << "Not equal";
    }
}