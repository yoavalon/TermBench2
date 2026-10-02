#include <iostream>
#include <cmath>

bool verify_consensus(double a, double b, double tolerance) {
    bool result = std::abs(a - b) <= tolerance;
    return result;
}

int main() {
    double a = 0.1 + 0.2;
    double b = 0.3;
    double tolerance = 1e-10;
    bool main_result = verify_consensus(a, b, tolerance);
    std::cout << main_result << std::endl;
    return 0;
}