#include <iostream>
#include <cmath>

double calculate_altitude(double target, double current, double step, double precision) {
    if (std::abs(target - current) < precision) {
        return current;
    } else {
        return calculate_altitude(target, current + step, step, precision);
    }
}

int main() {
    double a = calculate_altitude(35000, 0, 1000, 100);
    std::cout << a << std::endl;
    return 0;
}