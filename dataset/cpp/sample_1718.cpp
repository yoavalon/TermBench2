#include <iostream>
#include <cmath>

class Transformation {
public:
    Transformation(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
        matrix[0][0] = a; matrix[0][1] = b; matrix[0][2] = c;
        matrix[1][0] = d; matrix[1][1] = e; matrix[1][2] = f;
        matrix[2][0] = g; matrix[2][1] = h; matrix[2][2] = i;
    }

    std::tuple<double, double, double> apply(std::tuple<double, double, double> point) {
        double x, y, z;
        std::tie(x, y, z) = point;
        double new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z;
        double new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z;
        double new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z;
        return std::make_tuple(new_x, new_y, new_z);
    }

private:
    double matrix[3][3];
};

std::tuple<double, double, double> rotate_x(std::tuple<double, double, double> point, double angle) {
    double cos_angle = std::cos(angle);
    double sin_angle = std::sin(angle);
    Transformation t(1, 0, 0, 0, cos_angle, -sin_angle, 0, sin_angle, cos_angle);
    return t.apply(point);
}

std::tuple<double, double, double> rotate_y(std::tuple<double, double, double> point, double angle) {
    double cos_angle = std::cos(angle);
    double sin_angle = std::sin(angle);
    Transformation t(cos_angle, 0, sin_angle, 0, 1, 0, -sin_angle, 0, cos_angle);
    return t.apply(point);
}

std::tuple<double, double, double> rotate_z(std::tuple<double, double, double> point, double angle) {
    double cos_angle = std::cos(angle);
    double sin_angle = std::sin(angle);
    Transformation t(cos_angle, -sin_angle, 0, sin_angle, cos_angle, 0, 0, 0, 1);
    return t.apply(point);
}

void main() {
    std::tuple<double, double, double> point(1, 1, 1);
    double angle = M_PI / 4;
    while (true) {
        point = rotate_x(point, angle);
        point = rotate_y(point, angle);
        point = rotate_z(point, angle);
        double x, y, z;
        std::tie(x, y, z) = point;
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
}