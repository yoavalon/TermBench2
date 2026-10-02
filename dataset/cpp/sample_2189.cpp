#include <iostream>
#include <tuple>

std::tuple<double, double, double> simulate(double a, double b, double c) {
    while (true) {
        double next_a = b;
        double next_b = c;
        double next_c = (a + b + c) / 3.0;
        a = next_a;
        b = next_b;
        c = next_c;
        yield (a, b, c);
    }
}

void main() {
    auto [x, y, z] = simulate(1.0, 2.0, 3.0);
    std::cout << x << ", " << y << ", " << z << std::endl;
}