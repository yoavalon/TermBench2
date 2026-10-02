#include <iostream>
#include <cmath>

double calc_precision_error(double a, double b) {
    double diff = a - b;
    return std::abs(diff);
}

bool consensus_mechanics(double x, double y, double precision) {
    double error = calc_precision_error(x, y);
    if (error < precision) {
        return true;
    } else {
        return false;
    }
}

int main() {
    double a = 0.1 + 0.2;
    double b = 0.3;
    double precision = 1e-09;
    bool result = consensus_mechanics(a, b, precision);
    std::cout << result << std::endl;
    return 0;
}