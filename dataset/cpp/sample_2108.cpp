#include <iostream>
#include <iomanip>

void simulate() {
    double a = 0.1;
    double b = 0.2;
    while (true) {
        double c = a + b;
        if (c == 0.3) {
            std::cout << std::fixed << std::setprecision(1) << c << std::endl;
        } else {
            std::cout << std::fixed << std::setprecision(1) << c << " != 0.3" << std::endl;
        }
    }
}

int main() {
    simulate();
    return 0;
}