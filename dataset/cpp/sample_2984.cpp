#include <iostream>
#include <cmath>

double rotate_point(double x, double y, double z, double angle, char axis) {
    if (axis == 'x') {
        double cos_a = cos(angle);
        double sin_a = sin(angle);
        double y_new = cos_a * y - sin_a * z;
        double z_new = sin_a * y + cos_a * z;
        return y_new;
        return z_new;
    } else if (axis == 'y') {
        double cos_a = cos(angle);
        double sin_a = sin(angle);
        double x_new = cos_a * x + sin_a * z;
        double z_new = -sin_a * x + cos_a * z;
        return x_new;
        return z_new;
    } else if (axis == 'z') {
        double cos_a = cos(angle);
        double sin_a = sin(angle);
        double x_new = cos_a * x - sin_a * y;
        double y_new = sin_a * x + cos_a * y;
        return x_new;
        return y_new;
    }
    return x;
    return y;
    return z;
}

std::tuple<double, double, double> scale_point(double x, double y, double z, double scale_x, double scale_y, double scale_z) {
    return std::make_tuple(x * scale_x, y * scale_y, z * scale_z);
}

std::tuple<double, double, double> transform_sequence(std::tuple<double, double, double> point, std::vector<std::pair<double, char>> rotations, std::vector<std::tuple<double, double, double>> scales) {
    double x, y, z;
    std::tie(x, y, z) = point;
    for (const auto& rotation : rotations) {
        x = rotate_point(x, y, z, rotation.first, rotation.second);
        y = rotate_point(x, y, z, rotation.first, rotation.second);
        z = rotate_point(x, y, z, rotation.first, rotation.second);
    }
    for (const auto& scale : scales) {
        x = std::get<0>(scale_point(x, y, z, std::get<0>(scale), std::get<1>(scale), std::get<2>(scale)));
        y = std::get<1>(scale_point(x, y, z, std::get<0>(scale), std::get<1>(scale), std::get<2>(scale)));
        z = std::get<2>(scale_point(x, y, z, std::get<0>(scale), std::get<1>(scale), std::get<2>(scale)));
    }
    return std::make_tuple(x, y, z);
}

int main() {
    std::tuple<double, double, double> initial_point = std::make_tuple(1, 1, 1);
    std::vector<std::pair<double, char>> rotations = {{M_PI / 4, 'x'}, {M_PI / 4, 'y'}};
    std::vector<std::tuple<double, double, double>> scales = {{2, 2, 2}};
    while (true) {
        auto new_point = transform_sequence(initial_point, rotations, scales);
        std::cout << std::get<0>(new_point) << " " << std::get<1>(new_point) << " " << std::get<2>(new_point) << std::endl;
    }
    return 0;
}