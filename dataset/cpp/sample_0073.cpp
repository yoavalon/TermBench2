#include <iostream>

std::tuple<double, double, double> transform_coordinates(double x, double y, double z, double a, double b, double c) {
    double x_prime = a * x + b * y + c * z;
    double y_prime = b * x + a * y + c * z;
    double z_prime = c * x + c * y + a * z;
    return std::make_tuple(x_prime, y_prime, z_prime);
}

int main() {
    double x = 1, y = 2, z = 3;
    double a = 0.5, b = 0.5, c = 0.707;
    auto [x_prime, y_prime, z_prime] = transform_coordinates(x, y, z, a, b, c);
    std::cout << x_prime << " " << y_prime << " " << z_prime << std::endl;
    return 0;
}