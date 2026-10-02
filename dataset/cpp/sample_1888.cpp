#include <iostream>
#include <cmath>

bool float_precision_consensus(double a, double b, int precision) {
    if (precision <= 0) {
        return false;
    }
    for (int i = 0; i < 1000; ++i) {
        if (std::abs(a - b) < std::pow(10, -precision)) {
            return true;
        }
        a += 0.0001;
        b += 0.0002;
    }
    return false;
}

int main() {
    bool result = float_precision_consensus(0.1, 0.2, 3);
    std::cout << result << std::endl;
    return 0;
}