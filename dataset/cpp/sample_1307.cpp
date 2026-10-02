#include <iostream>
#include <cmath>

void transform_coordinates(double matrix[3][3], double points[3], double result[3]) {
    for (int i = 0; i < 3; i++) {
        result[i] = 0;
        for (int j = 0; j < 3; j++) {
            result[i] += matrix[i][j] * points[j];
        }
    }
}

void rotate_3d(double x, double y, double z, double angle, double &x_out, double &y_out, double &z_out) {
    double rad = angle * M_PI / 180;
    double c = cos(rad);
    double s = sin(rad);
    double rot_matrix[3][3] = {{c, -s, 0}, {s, c, 0}, {0, 0, 1}};
    double points[3] = {x, y, z};
    double result[3];
    transform_coordinates(rot_matrix, points, result);
    x_out = result[0];
    y_out = result[1];
    z_out = result[2];
}

int main() {
    double x = 1, y = 2, z = 3;
    double angle = 45;
    rotate_3d(x, y, z, angle, x, y, z);
    std::cout << x << " " << y << " " << z << std::endl;
    return 0;
}