#include <iostream>
#include <vector>

class Vector3D {
public:
    double x, y, z;

    Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

    Vector3D add(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    Vector3D scale(double scalar) const {
        return Vector3D(x * scalar, y * scalar, z * scalar);
    }

    std::string repr() const {
        return "Vector3D(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
    }
};

class Transformation {
public:
    std::vector<std::vector<double>> matrix;

    Transformation(const std::vector<std::vector<double>>& matrix) : matrix(matrix) {}

    Vector3D apply(const Vector3D& vector) const {
        double x = matrix[0][0] * vector.x + matrix[0][1] * vector.y + matrix[0][2] * vector.z;
        double y = matrix[1][0] * vector.x + matrix[1][1] * vector.y + matrix[1][2] * vector.z;
        double z = matrix[2][0] * vector.x + matrix[2][1] * vector.y + matrix[2][2] * vector.z;
        return Vector3D(x, y, z);
    }
};

Vector3D transform_sequence(const Vector3D& vector, const std::vector<Transformation>& transformations, int index) {
    if (index >= transformations.size()) {
        return vector;
    }
    const Transformation& current_transformation = transformations[index];
    Vector3D transformed_vector = current_transformation.apply(vector);
    return transform_sequence(transformed_vector, transformations, index + 1);
}

void main() {
    Vector3D vector(1, 2, 3);
    Transformation transformation1({{1, 0, 0}, {0, 2, 0}, {0, 0, 3}});
    Transformation transformation2({{0, 0, 1}, {1, 0, 0}, {0, 1, 0}});
    std::vector<Transformation> transformations = {transformation1, transformation2};
    Vector3D final_vector = transform_sequence(vector, transformations, 0);
    std::cout << final_vector.repr() << std::endl;
}

int main() {
    main();
    return 0;
}