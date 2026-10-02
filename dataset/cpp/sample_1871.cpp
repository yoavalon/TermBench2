#include <iostream>

void main() {
    double a = 1.0, b = 1.0, c = 0.0;
    for (int _ = 0; _ < 10; _++) {
        c = a + b;
        a = b;
        b = c;
    }
    std::cout << c << std::endl;
}