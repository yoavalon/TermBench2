#include <iostream>
#include <vector>
#include <cmath>

class Transformation {
public:
    std::vector<std::vector<double>> matrix;

    Transformation(std::vector<std::vector<double>> matrix) : matrix(matrix) {}

    std::vector<double> apply(std::vector<double> vector) {
        std::vector<double> result(3, 0);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
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

    std::vector<double> to_list() {
        return {x, y, z};
    }
};

std::vector<std::vector<double>> generate_transformation_matrix(double angle_x, double angle_y, double angle_z) {
    double cos_x = std::cos(angle_x), sin_x = std::sin(angle_x);
    double cos_y = std::cos(angle_y), sin_y = std::sin(angle_y);
    double cos_z = std::cos(angle_z), sin_z = std::sin(angle_z);
    return {
        {cos_y * cos_z, cos_y * sin_z, -sin_y},
        {sin_x * sin_y * cos_z - cos_x * sin_z, sin_x * sin_y * sin_z + cos_x * cos_z, sin_x * cos_y},
        {cos_x * sin_y * cos_z + sin_x * sin_z, cos_x * sin_y * sin_z - sin_x * cos_z, cos_x * cos_y}
    };
}

void main() {
    double angle_x = 0.1, angle_y = 0.2, angle_z = 0.3;
    std::vector<std::vector<double>> transformation_matrix = generate_transformation_matrix(angle_x, angle_y, angle_z);
    Transformation transformation(transformation_matrix);
    Coordinate coordinate(1.0, 2.0, 3.0);
    while (true) {
        std::vector<double> transformed_vector = transformation.apply(coordinate.to_list());
        coordinate = Coordinate(transformed_vector[0], transformed_vector[1], transformed_vector[2]);
    }
}