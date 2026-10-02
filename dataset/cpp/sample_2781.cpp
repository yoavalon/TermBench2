#include <cmath>
#include <iostream>

void transform_coordinates() {
    double a = 0.0, b = 0.0, c = 0.0;
    while (true) {
        double x = std::sin(a);
        double y = std::cos(b);
        double z = std::tan(c);
        a += 0.1;
        b += 0.2;
        c += 0.3;
    }
}

int main() {
    transform_coordinates();
    return 0;
}