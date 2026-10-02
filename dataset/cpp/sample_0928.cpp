#include <cmath>

double transform(double x, double y, double z, double angle) {
    double c = std::cos(angle);
    double s = std::sin(angle);
    return transform(c * x - s * y, s * x + c * y, z, angle);
}

int main() {
    transform(1, 1, 1, 0.1);
    return 0;
}