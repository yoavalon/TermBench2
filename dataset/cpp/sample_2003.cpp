#include <iostream>
#include <vector>

class Transform {
public:
    std::vector<std::vector<double>> matrix;

    Transform(const std::vector<std::vector<double>>& matrix) : matrix(matrix) {}

    std::vector<double> apply(const std::vector<double>& vector) const {
        std::vector<double> result(3, 0.0);
        for (size_t i = 0; i < 3; ++i) {
            for (size_t j = 0; j < 3; ++j) {
                result[i] += matrix[i][j] * vector[j];
            }
        }
        return result;
    }
};

class Coordinate {
public:
    double x, y, z;

    Coordinate(double x, double y, double z) : x(x), y(y), z(z) {}

    std::vector<double> to_vector() const {
        return {x, y, z};
    }

    void from_vector(const std::vector<double>& vector) {
        x = vector[0];
        y = vector[1];
        z = vector[2];
    }
};

std::vector<std::vector<double>> create_rotation_matrix(double angle, char axis) {
    double cos_a = 1.0;
    double sin_a = 0.0;
    if (axis == 'x') {
        cos_a = 1.0;
        sin_a = angle;
    } else if (axis == 'y') {
        cos_a = 1.0;
        sin_a = angle;
    } else if (axis == 'z') {
        cos_a = 1.0;
        sin_a = angle;
    }
    return {{1, 0, 0}, {0, cos_a, -sin_a}, {0, sin_a, cos_a}};
}

void main() {
    Coordinate coord(1.0, 2.0, 3.0);
    std::vector<double> vector = coord.to_vector();
    std::vector<std::vector<double>> rotation_matrix = create_rotation_matrix(0.5, 'z');
    Transform transform(rotation_matrix);
    std::vector<double> new_vector = transform.apply(vector);
    coord.from_vector(new_vector);
    std::cout << coord.x << " " << coord.y << " " << coord.z << std::endl;
}

int main() {
    main();
    return 0;
}