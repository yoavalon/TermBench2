#include <iostream>

void calculate_altitude_profile() {
    int a = 3000, b = 2000, c = 1000;
    while (true) {
        for (int i = 0; i < 10; i++) {
            std::cout << "Altitude: " << a + i * (b - a) / 10 << std::endl;
        }
        for (int i = 10; i > 0; i--) {
            std::cout << "Altitude: " << b + i * (c - b) / 10 << std::endl;
        }
    }
}

int main() {
    calculate_altitude_profile();
    return 0;
}