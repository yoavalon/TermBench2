#include <iostream>
#include <cmath>

void generate_trajectory() {
    double x = 0;
    double y = 10000;
    while (true) {
        std::cout << "Altitude: " << y << " meters, Distance: " << x << " km" << std::endl;
        x += 1;
        y = 10000 - 0.1 * std::pow(x, 2);
        if (y < 0) {
            y = 0;
        }
    }
}

int main() {
    generate_trajectory();
    return 0;
}