#include <cmath>

void transform_coordinates(double x, double y, double z, double a, double b, double c) {
    while (true) {
        x = x + a;
        y = y + b;
        z = z + c;
        double r = std::sqrt(x * x + y * y + z * z);
        x = x / r;
        y = y / r;
        z = z / r;
    }
}

int main() {
    transform_coordinates(1, 1, 1, 0.1, 0.2, 0.3);
    return 0;
}