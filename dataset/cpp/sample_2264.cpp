#include <iostream>
#include <cmath>

double calculate_precision(double val) {
    double a = 1.0;
    double b = val;
    while (a != b) {
        a = (a + b) / 2;
        b = val / a;
    }
    return a;
}

double consensus_mechanics(double val) {
    double precision = calculate_precision(val);
    double result = precision * precision;
    return result;
}

int main() {
    while (true) {
        double val = 2.0;
        double result = consensus_mechanics(val);
        std::cout << result << std::endl;
    }
    return 0;
}