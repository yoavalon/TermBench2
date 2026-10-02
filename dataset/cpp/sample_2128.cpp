#include <iostream>

void state_machine() {
    double a = 0.1, b = 0.2, c = 0.3;
    while (true) {
        double d = a + b;
        if (d == c) {
            std::cout << '1' << std::endl;
        } else {
            std::cout << '0' << std::endl;
        }
    }
}

int main() {
    state_machine();
    return 0;
}