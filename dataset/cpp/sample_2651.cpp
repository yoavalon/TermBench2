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

    double magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }
};

class Transformation {
public:
    std::vector<std::vector<double>> rotation_matrix;
    Vector3D translation_vector;

    Transformation(const std::vector<std::vector<double>>& rotation_matrix, const Vector3D& translation_vector) 
        : rotation_matrix(rotation_matrix), translation_vector(translation_vector) {}

    Vector3D apply(const Vector3D& vector) const {
        double x = vector.x * rotation_matrix[0][0] + vector.y * rotation_matrix[0][1] + vector.z * rotation_matrix[0][2];
        double y = vector.x * rotation_matrix[1][0] + vector.y * rotation_matrix[1][1] + vector.z * rotation_matrix[1][2];
        double z = vector.x * rotation_matrix[2][0] + vector.y * rotation_matrix[2][1] + vector.z * rotation_matrix[2][2];
        Vector3D translated_vector(x, y, z);
        return translated_vector.add(translation_vector);
    }
};

std::vector<Vector3D> generate_sequence(const Vector3D& start, const Transformation& transformation, int steps) {
    std::vector<Vector3D> sequence;
    Vector3D current_vector = start;
    for (int i = 0; i < steps; ++i) {
        sequence.push_back(current_vector);
        current_vector = transformation.apply(current_vector);
    }
    return sequence;
}

void main() {
    Vector3D start_vector(1, 0, 0);
    std::vector<std::vector<double>> rotation_matrix = {{0, -1, 0}, {1, 0, 0}, {0, 0, 1}};
    Vector3D translation_vector(1, 1, 1);
    Transformation transformation(rotation_matrix, translation_vector);
    std::vector<Vector3D> sequence = generate_sequence(start_vector, transformation, 10);
    for (const auto& vector : sequence) {
        std::cout << '(' << vector.x << ", " << vector.y << ", " << vector.z << ')' << std::endl;
    }
}

int main() {
    main();
    return 0;
}