#include <iostream>

void transform(double& x, double& y, double& z, double a, double b, double c) {
    x = a * x + b * y + c * z;
    y = b * x + a * y;
    z = c * x + y;
    transform(x, y, z, a, b, c);
}

int main() {
    double x = 1, y = 1, z = 1, a = 1.5, b = -0.5, c = 0;
    transform(x, y, z, a, b, c);
    return 0;
}