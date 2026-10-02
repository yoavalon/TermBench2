#include <iostream>

void main() {
    double x = 0;
    double decay_rate = 0.99;
    while (true) {
        x *= decay_rate;
        if (x < 0.01) {
            x = 1;
        }
        std::cout << x << std::endl;
    }
}