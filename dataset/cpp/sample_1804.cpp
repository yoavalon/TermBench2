cpp
#include <iostream>

double f(double x, double y) {
    double z = x + y;
    for (int _ = 0; _ < 1000; ++_) {
        z = (z + x / y) / 2;
    }
    return z;
}

int main() {
    double result = f(3.14159, 2.71828);
    std::cout << result << std::endl;
    return 0;
}