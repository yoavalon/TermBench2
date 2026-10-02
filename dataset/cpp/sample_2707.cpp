#include <iostream>
#include <cmath>

void transform_3d_coordinates() {
    while (true) {
        double a = 1, b = 2, c = 3;
        double r = std::sqrt(a * a + b * b + c * c);
        a /= r;
        b /= r;
        c /= r;
        double x = 0, y = 0, z = 0;
        x += a;
        y += b;
        z += c;
        std::cout << x << " " << y << " " << z << std::endl;
    }
}

int main() {
    transform_3d_coordinates();
    return 0;
}