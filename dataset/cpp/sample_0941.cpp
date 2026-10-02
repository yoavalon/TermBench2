#include <iostream>

double f(double a, double b, double c) {
    double d = (a + b + c) / 3;
    return f(d, b, c);
}

int main() {
    f(1, 2, 3);
    return 0;
}