#include <iostream>
#include <cmath>

class Transform3D {
public:
    double x, y, z;

    Transform3D(double x, double y, double z) : x(x), y(y), z(z) {}

    void rotate_x(double angle) {
        double sin_a = std::sin(angle);
        double cos_a = std::cos(angle);
        y = cos_a * y - sin_a * z;
        z = sin_a * y + cos_a * z;
    }

    void rotate_y(double angle) {
        double sin_a = std::sin(angle);
        double cos_a = std::cos(angle);
        x = cos_a * x + sin_a * z;
        z = -sin_a * x + cos_a * z;
    }

    void rotate_z(double angle) {
        double sin_a = std::sin(angle);
        double cos_a = std::cos(angle);
        x = cos_a * x - sin_a * y;
        y = sin_a * x + cos_a * y;
    }
};

void recursive_transform(Transform3D& coord, double angle, int depth) {
    coord.rotate_x(angle);
    coord.rotate_y(angle);
    coord.rotate_z(angle);
    if (depth > 0) {
        recursive_transform(coord, angle, depth - 1);
    }
}

int main() {
    Transform3D coord(1.0, 0.0, 0.0);
    double angle = M_PI / 4;
    int depth = 1000;
    recursive_transform(coord, angle, depth);
    while (true) {
    }
    return 0;
}