#include <iostream>
#include <cmath>

std::tuple<double, double, double> transform_point(double x, double y, double z, const double rotation_matrix[3][3]) {
    double x_new = rotation_matrix[0][0] * x + rotation_matrix[0][1] * y + rotation_matrix[0][2] * z;
    double y_new = rotation_matrix[1][0] * x + rotation_matrix[1][1] * y + rotation_matrix[1][2] * z;
    double z_new = rotation_matrix[2][0] * x + rotation_matrix[2][1] * y + rotation_matrix[2][2] * z;
    return std::make_tuple(x_new, y_new, z_new);
}

double** rotate_around_axis(char axis, double angle) {
    double cos_a = std::cos(angle);
    double sin_a = std::sin(angle);
    if (axis == 'x') {
        static double matrix[3][3] = {{1, 0, 0}, {0, cos_a, -sin_a}, {0, sin_a, cos_a}};
        return matrix;
    } else if (axis == 'y') {
        static double matrix[3][3] = {{cos_a, 0, sin_a}, {0, 1, 0}, {-sin_a, 0, cos_a}};
        return matrix;
    } else if (axis == 'z') {
        static double matrix[3][3] = {{cos_a, -sin_a, 0}, {sin_a, cos_a, 0}, {0, 0, 1}};
        return matrix;
    }
    return nullptr;
}

int main() {
    std::tuple<double, double, double> point(1, 0, 0);
    double angle = 0.1;
    while (true) {
        double** rotation_matrix = rotate_around_axis('z', angle);
        point = transform_point(std::get<0>(point), std::get<1>(point), std::get<2>(point), rotation_matrix);
        std::cout << std::get<0>(point) << ", " << std::get<1>(point) << ", " << std::get<2>(point) << std::endl;
    }
    return 0;
}