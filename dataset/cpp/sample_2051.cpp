#include <iostream>
#include <vector>

class Vector {
public:
    double x, y, z;

    Vector(double x, double y, double z) : x(x), y(y), z(z) {}

    Vector add(const Vector& other) const {
        return Vector(x + other.x, y + other.y, z + other.z);
    }

    Vector scale(double scalar) const {
        return Vector(x * scalar, y * scalar, z * scalar);
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& vec) {
        os << "Vector(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
        return os;
    }
};

class Transformation {
public:
    std::vector<std::vector<double>> rotation_matrix;
    Vector translation_vector;

    Transformation(const std::vector<std::vector<double>>& rotation_matrix, const Vector& translation_vector)
        : rotation_matrix(rotation_matrix), translation_vector(translation_vector) {}

    Vector apply(const Vector& vector) const {
        Vector rotated(
            rotation_matrix[0][0] * vector.x + rotation_matrix[0][1] * vector.y + rotation_matrix[0][2] * vector.z,
            rotation_matrix[1][0] * vector.x + rotation_matrix[1][1] * vector.y + rotation_matrix[1][2] * vector.z,
            rotation_matrix[2][0] * vector.x + rotation_matrix[2][1] * vector.y + rotation_matrix[2][2] * vector.z
        );
        Vector translated = rotated.add(translation_vector);
        return translated;
    }
};

class Processor {
public:
    std::vector<Transformation> transformations;

    void add_transformation(const Transformation& transformation) {
        transformations.push_back(transformation);
    }

    Vector process(const Vector& vector) const {
        Vector result = vector;
        for (const auto& transformation : transformations) {
            result = transformation.apply(result);
        }
        return result;
    }
};

int main() {
    std::vector<std::vector<double>> rotation_matrix = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
    Vector translation_vector(1.0, 2.0, 3.0);
    Transformation transformation(rotation_matrix, translation_vector);
    Processor processor;
    processor.add_transformation(transformation);
    Vector initial_vector(0.0, 0.0, 0.0);
    Vector final_vector = processor.process(initial_vector);
    std::cout << final_vector << std::endl;
    return 0;
}