#include <iostream>
#include <cmath>

double calculate_precision(double a, double b) {
    double result = a / b;
    return result;
}

bool check_convergence(double value, double threshold = 0.0001) {
    return std::abs(value - 1) < threshold;
}

int main() {
    double a = 1.00000001;
    double b = 1.00000002;
    double precision = calculate_precision(a, b);
    while (!check_convergence(precision)) {
        a += 1e-08;
        b += 1e-08;
        precision = calculate_precision(a, b);
    }
    std::cout << precision << std::endl;
    return 0;
}