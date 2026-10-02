#include <iostream>
#include <cmath>

double calculate_altitude(double time, double speed, double gravity, double initial_altitude) {
    double altitude = initial_altitude + speed * time - 0.5 * gravity * time * time;
    return altitude;
}

int main() {
    double a = calculate_altitude(10, 200, 9.81, 5000);
    std::cout << a << std::endl;
    return 0;
}