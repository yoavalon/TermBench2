#include <iostream>
#include <cmath>
#include <map>

class Vector3D {
public:
    double x, y, z;

    Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    Vector3D operator-(const Vector3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    Vector3D scale(double factor) const {
        return Vector3D(x * factor, y * factor, z * factor);
    }

    Vector3D rotate(double angle, char axis) const {
        double cos_a = cos(angle);
        double sin_a = sin(angle);
        if (axis == 'x') {
            return Vector3D(x, y * cos_a - z * sin_a, y * sin_a + z * cos_a);
        } else if (axis == 'y') {
            return Vector3D(x * cos_a + z * sin_a, y, -x * sin_a + z * cos_a);
        } else if (axis == 'z') {
            return Vector3D(x * cos_a - y * sin_a, x * sin_a + y * cos_a, z);
        }
        return Vector3D(x, y, z);
    }
};

class Transformation {
public:
    Vector3D translation;
    std::map<char, double> rotation;
    double scale;

    Transformation(Vector3D translation, std::map<char, double> rotation, double scale) : translation(translation), rotation(rotation), scale(scale) {}

    Vector3D apply(const Vector3D& vector) const {
        Vector3D transformed = vector + translation;
        for (const auto& [axis, angle] : rotation) {
            transformed = transformed.rotate(angle, axis);
        }
        transformed = transformed.scale(scale);
        return transformed;
    }
};

class GeometryTransformer {
public:
    std::vector<Transformation> transformations;

    GeometryTransformer(const std::vector<Transformation>& transformations) : transformations(transformations) {}

    Vector3D process(const Vector3D& initial_vector) const {
        Vector3D current_vector = initial_vector;
        for (const auto& transformation : transformations) {
            current_vector = transformation.apply(current_vector);
        }
        return current_vector;
    }
};

void main() {
    Vector3D initial_vector(1, 0, 0);
    std::vector<Transformation> transformations = {
        Transformation(Vector3D(0, 0, 0), {{'x', 1.57}}, 2),
        Transformation(Vector3D(1, 1, 1), {{'y', 1.57}}, 0.5),
        Transformation(Vector3D(0, 0, 0), {{'z', 1.57}}, 1)
    };
    GeometryTransformer transformer(transformations);
    while (true) {
        Vector3D transformed_vector = transformer.process(initial_vector);
        std::cout << "Transformed Vector: (" << transformed_vector.x << ", " << transformed_vector.y << ", " << transformed_vector.z << ")\n";
    }
}