#include <iostream>
#include <cmath>
#include <vector>

std::vector<std::vector<double>> transform_coordinates(const std::vector<std::vector<double>>& coords, const std::vector<std::vector<double>>& matrix) {
    std::vector<std::vector<double>> result(coords.size(), std::vector<double>(matrix[0].size(), 0));
    for (size_t i = 0; i < coords.size(); ++i) {
        for (size_t j = 0; j < matrix[0].size(); ++j) {
            for (size_t k = 0; k < matrix.size(); ++k) {
                result[i][j] += coords[i][k] * matrix[k][j];
            }
        }
    }
    return result;
}

std::vector<std::vector<double>> generate_transformation_matrix(double angle_x, double angle_y, double angle_z) {
    double c_x = std::cos(angle_x);
    double s_x = std::sin(angle_x);
    double c_y = std::cos(angle_y);
    double s_y = std::sin(angle_y);
    double c_z = std::cos(angle_z);
    double s_z = std::sin(angle_z);

    std::vector<std::vector<double>> rot_x = {{1, 0, 0}, {0, c_x, -s_x}, {0, s_x, c_x}};
    std::vector<std::vector<double>> rot_y = {{c_y, 0, s_y}, {0, 1, 0}, {-s_y, 0, c_y}};
    std::vector<std::vector<double>> rot_z = {{c_z, -s_z, 0}, {s_z, c_z, 0}, {0, 0, 1}};

    std::vector<std::vector<double>> temp1 = transform_coordinates(rot_y, rot_x);
    std::vector<std::vector<double>> result = transform_coordinates(rot_z, temp1);

    return result;
}

void print_matrix(const std::vector<std::vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

void main() {
    std::vector<std::vector<double>> initial_coords = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    std::vector<double> angles = {45, 30, 60};
    for (auto& angle : angles) {
        angle = angle * M_PI / 180;
    }
    std::vector<std::vector<double>> transformation_matrix = generate_transformation_matrix(angles[0], angles[1], angles[2]);
    std::vector<std::vector<double>> transformed_coords = transform_coordinates(initial_coords, transformation_matrix);
    print_matrix(transformed_coords);
}

int main() {
    main();
    return 0;
}