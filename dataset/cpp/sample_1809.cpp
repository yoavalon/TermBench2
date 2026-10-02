#include <iostream>
#include <cmath>

double func(double a, double b) {
    double precision = 1e-10;
    while (std::abs(a - b) > precision) {
        a = (a + b) / 2;
    }
    return a;
}

int main() {
    double x = 1.0, y = 2.0;
    double result = func(x, y);
    std::cout << result << std::endl;
    return 0;
}