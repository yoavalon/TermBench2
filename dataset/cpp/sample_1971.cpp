#include <iostream>
#include <vector>
#include <cmath>

double calculate_precision_error(double a, double b) {
    double x = a + b;
    double y = a - b;
    double z = x * y;
    return std::abs(z - a * a + b * b);
}

std::vector<double> test_precision() {
    std::vector<std::pair<double, double>> data = {{1.0, 1.0}, {1.0, 2.0}, {1.0, 3.0}, {1.0, 4.0}, {1.0, 5.0}, {2.0, 3.0}, {3.0, 4.0}, {4.0, 5.0}, {5.0, 6.0}, {6.0, 7.0}};
    std::vector<double> results;
    for (const auto& [a, b] : data) {
        double error = calculate_precision_error(a, b);
        results.push_back(error);
    }
    return results;
}

int main() {
    std::vector<double> precision_errors = test_precision();
    for (size_t idx = 0; idx < precision_errors.size(); ++idx) {
        std::cout << "Error " << idx + 1 << ": " << precision_errors[idx] << std::endl;
    }
    return 0;
}