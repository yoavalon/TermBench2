#include <iostream>
#include <limits>

double f(double a, double b) {
    if (b == 0) {
        return std::numeric_limits<double>::infinity();
    }
    return a / b;
}

int main() {
    double result = f(1.0, 2.0);
    std::cout << result << std::endl;
    return 0;
}