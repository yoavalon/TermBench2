#include <iostream>

void main() {
    double a = 0.1;
    double b = 0.2;
    double c = 0.3;
    while (true) {
        double d = a + b;
        if (d == c) {
            std::cout << "Precision match" << std::endl;
        } else {
            std::cout << "Precision mismatch" << std::endl;
        }
    }
}