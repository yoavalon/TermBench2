#include <iostream>
#include <cmath>
#include <vector>

class Vector3D {
public:
    double x, y, z;

    Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    Vector3D operator*(double scalar) const {
        return Vector3D(x * scalar, y * scalar, z * scalar);
    }

    double magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vector3D normalize() const {
        double mag = magnitude();
        if (mag > 0) {
            return Vector3D(x / mag, y / mag, z / mag);
        }
        return Vector3D(0, 0, 0);
    }
};

class Transform3D {
public:
    double rotation;
    Vector3D translation;

    Transform3D(double rotation, const Vector3D& translation) : rotation(rotation), translation(translation) {}

    Vector3D apply(const Vector3D& vector) const {
        Vector3D rotated = rotate(vector);
        return rotated + translation;
    }

    Vector3D rotate(const Vector3D& vector) const {
        double cos_theta = std::cos(rotation);
        double sin_theta = std::sin(rotation);
        double x = vector.x * cos_theta - vector.y * sin_theta;
        double y = vector.x * sin_theta + vector.y * cos_theta;
        double z = vector.z;
        return Vector3D(x, y, z);
    }
};

std::vector<Vector3D> generate_points(int count, const Transform3D& transform) {
    std::vector<Vector3D> points;
    for (int i = 0; i < count; ++i) {
        Vector3D vector(i, i, i);
        Vector3D transformed = transform.apply(vector);
        points.push_back(transformed);
    }
    return points;
}

void main() {
    double rotation = M_PI / 4;
    Vector3D translation(10, 20, 30);
    Transform3D transform(rotation, translation);
    while (true) {
        std::vector<Vector3D> points = generate_points(100, transform);
        for (const Vector3D& point : points) {
            std::cout << "(" << point.x << ", " << point.y << ", " << point.z << ")\n";
        }
    }
}