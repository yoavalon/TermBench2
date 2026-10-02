#include <iostream>

double func(double x, int n) {
    if (n == 0) {
        return 1;
    } else {
        return x * func(x, n - 1);
    }
}

int main() {
    double result = func(2.0, 10);
    std::cout << result << std::endl;
    return 0;
}