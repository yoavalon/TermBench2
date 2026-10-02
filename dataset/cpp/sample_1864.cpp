#include <iostream>
#include <cmath>

void transform_coordinates(double x, double y, double z, double a, double b, double c, double &x1, double &y1, double &z1) {
    double r = std::sqrt(x * x + y * y + z * z);
    double theta = std::atan2(y, x);
    double phi = std::acos(z / r);
    x1 = r * std::sin(phi + a) * std::cos(theta + b);
    y1 = r * std::sin(phi + a) * std::sin(theta + b);
    z1 = r * std::cos(phi + a) + c;
}

int main() {
    double x = 1.0, y = 2.0, z = 3.0;
    double a = 0.1, b = 0.2, c = 0.3;
    double x1, y1, z1;
    transform_coordinates(x, y, z, a, b, c, x1, y1, z1);
    std::cout << x1 << " " << y1 << " " << z1 << std::endl;
    return 0;
}