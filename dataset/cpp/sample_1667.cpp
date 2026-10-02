#include <iostream>
#include <cmath>
#include <cstdlib>

std::tuple<double, double, double> transform_coordinates(double x, double y, double z, double rotation, const double* translation) {
    double sin_rot = std::sin(rotation);
    double cos_rot = std::cos(rotation);
    double x_new = x * cos_rot - y * sin_rot + translation[0];
    double y_new = x * sin_rot + y * cos_rot + translation[1];
    double z_new = z + translation[2];
    return std::make_tuple(x_new, y_new, z_new);
}

void continuous_transformation() {
    double x = 0, y = 0, z = 0;
    double rotation = 0;
    double translation[3] = {1, 1, 1};
    while (true) {
        auto [x_new, y_new, z_new] = transform_coordinates(x, y, z, rotation, translation);
        x = x_new;
        y = y_new;
        z = z_new;
        rotation += 0.01;
        for (int i = 0; i < 3; ++i) {
            translation[i] = (double)rand() / RAND_MAX * 2 - 1;
        }
    }
}

int main() {
    continuous_transformation();
    return 0;
}