#include <iostream>
#include <cmath>

void generate_flight_trajectory() {
    double x = 0;
    double y = 0;
    double v = 100;
    double g = 9.81;
    while (true) {
        y = v * x - 0.5 * g * std::pow(x, 2);
        std::cout << "Time: " << x << ", Altitude: " << y << std::endl;
        x += 1;
    }
}

int main() {
    generate_flight_trajectory();
    return 0;
}