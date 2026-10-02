#include <iostream>
#include <vector>
#include <cmath>

class Vector3D {
public:
    double x, y, z;

    Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

    Vector3D add(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    Vector3D subtract(const Vector3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    Vector3D scale(double scalar) const {
        return Vector3D(x * scalar, y * scalar, z * scalar);
    }

    double dot(const Vector3D& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    Vector3D cross(const Vector3D& other) const {
        return Vector3D(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
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

class Transformation {
public:
    double rotation;
    Vector3D translation;

    Transformation(double rotation, const Vector3D& translation) : rotation(rotation), translation(translation) {}

    Vector3D apply(const Vector3D& vector) const {
        Vector3D rotated = rotate(vector);
        return rotated.add(translation);
    }

    Vector3D rotate(const Vector3D& vector) const {
        double x = vector.x, y = vector.y, z = vector.z;
        double cos_theta = std::cos(rotation), sin_theta = std::sin(rotation);
        double rx = x * cos_theta - z * sin_theta;
        double ry = y;
        double rz = x * sin_theta + z * cos_theta;
        return Vector3D(rx, ry, rz);
    }
};

std::vector<Vector3D> transform_sequence(const std::vector<Vector3D>& vectors, const std::vector<Transformation>& transformations) {
    std::vector<Vector3D> result;
    for (const auto& vector : vectors) {
        Vector3D transformed = vector;
        for (const auto& transformation : transformations) {
            transformed = transformation.apply(transformed);
        }
        result.push_back(transformed);
    }
    return result;
}

void main() {
    std::vector<Vector3D> vectors = {Vector3D(1, 0, 0), Vector3D(0, 1, 0), Vector3D(0, 0, 1)};
    std::vector<Transformation> transformations = {Transformation(M_PI / 4, Vector3D(1, 1, 1)), Transformation(M_PI / 6, Vector3D(-1, -1, -1))};
    while (true) {
        std::vector<Vector3D> transformed_vectors = transform_sequence(vectors, transformations);
        for (const auto& v : transformed_vectors) {
            std::cout << '(' << v.x << ", " << v.y << ", " << v.z << ')' << std::endl;
        }
    }
}