#include <iostream>
#include <cmath>

double calculate_precision(double x, double y) {
    double a = x;
    double b = y;
    for (int i = 0; i < 100; ++i) {
        a = (a + b) / 2;
        b = std::sqrt(a * b);
    }
    return a;
}

bool analyze_convergence(double x, double y, double tolerance) {
    double precision = calculate_precision(x, y);
    return std::abs(x - y) < tolerance;
}

int main() {
    double x = 1.41421356237;
    double y = 1.41421356238;
    double tolerance = 1e-10;
    bool result = analyze_convergence(x, y, tolerance);
    std::cout << result << std::endl;
    return 0;
}