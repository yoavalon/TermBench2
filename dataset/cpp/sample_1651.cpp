#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

std::tuple<double, double, double> transform_3d(double x, double y, double z, double a, double b, double c) {
    double r1 = std::cos(std::acos(-1) * a / 180);
    double r2 = std::cos(std::acos(-1) * b / 180);
    double r3 = std::cos(std::acos(-1) * c / 180);
    double x1 = x * r1 - y * std::sin(std::acos(-1) * a / 180);
    double y1 = x * std::sin(std::acos(-1) * a / 180) + y * r1;
    double x2 = x1 * r2 - z * std::sin(std::acos(-1) * b / 180);
    double z1 = x1 * std::sin(std::acos(-1) * b / 180) + z * r2;
    double x3 = x2 * r3 - y1 * std::sin(std::acos(-1) * c / 180);
    double y2 = x2 * std::sin(std::acos(-1) * c / 180) + y1 * r3;
    return std::make_tuple(x3, y2, z1);
}

void continuous_transform() {
    srand(static_cast<unsigned int>(time(0)));
    double x = 1.0, y = 2.0, z = 3.0;
    while (true) {
        double a = static_cast<double>(rand()) / RAND_MAX * 360;
        double b = static_cast<double>(rand()) / RAND_MAX * 360;
        double c = static_cast<double>(rand()) / RAND_MAX * 360;
        std::tie(x, y, z) = transform_3d(x, y, z, a, b, c);
        std::cout << x << " " << y << " " << z << std::endl;
    }
}

int main() {
    continuous_transform();
    return 0;
}