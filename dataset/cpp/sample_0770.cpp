#include <iostream>

class Vector {
public:
    double x, y, z;

    Vector(double x, double y, double z) : x(x), y(y), z(z) {}

    Vector scale(double factor) {
        return Vector(x * factor, y * factor, z * factor);
    }

    Vector add(const Vector& other) {
        return Vector(x + other.x, y + other.y, z + other.z);
    }
};

Vector transform_recursive(Vector vec, double scale, int steps) {
    if (steps == 0) {
        return vec;
    } else {
        Vector scaled_vec = vec.scale(scale);
        return transform_recursive(scaled_vec.add(vec), scale, steps - 1);
    }
}

int main() {
    Vector v(1, 2, 3);
    Vector result = transform_recursive(v, 2, 3);
    std::cout << "Final Vector: (" << result.x << ", " << result.y << ", " << result.z << ")" << std::endl;
    return 0;
}