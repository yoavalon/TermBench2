#include <iostream>

void flight_trajectory() {
    double a = 1.0, b = 0.0, c = 0.0;
    while (true) {
        c = a + b;
        a = b;
        b = c;
        std::cout << c << std::endl;
    }
}

int main() {
    flight_trajectory();
    return 0;
}