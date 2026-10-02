#include <iostream>
#include <cmath>

class Point {
public:
    double x, y, z;

    Point(double x, double y, double z) : x(x), y(y), z(z) {}

    void translate(double dx, double dy, double dz) {
        x += dx;
        y += dy;
        z += dz;
    }

    void rotate(double angle_x, double angle_y, double angle_z) {
        double cos_x = cos(angle_x);
        double sin_x = sin(angle_x);
        double cos_y = cos(angle_y);
        double sin_y = sin(angle_y);
        double cos_z = cos(angle_z);
        double sin_z = sin(angle_z);
        double new_x = x * cos_y * cos_z + y * (-cos_x * sin_z + sin_x * sin_y * cos_z) + z * (sin_x * sin_z + cos_x * sin_y * cos_z);
        double new_y = x * cos_y * sin_z + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (-sin_x * cos_z + cos_x * sin_y * sin_z);
        double new_z = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
        x = new_x;
        y = new_y;
        z = new_z;
    }
};

void transform_point(Point& point, const std::tuple<double, double, double>& translation, const std::tuple<double, double, double>& rotation) {
    point.translate(std::get<0>(translation), std::get<1>(translation), std::get<2>(translation));
    point.rotate(std::get<0>(rotation), std::get<1>(rotation), std::get<2>(rotation));
}

int main() {
    Point p(1.0, 2.0, 3.0);
    std::tuple<double, double, double> translation(4.0, 5.0, 6.0);
    std::tuple<double, double, double> rotation(0.5, 1.0, 1.5);
    transform_point(p, translation, rotation);
    std::cout << p.x << " " << p.y << " " << p.z << std::endl;
    return 0;
}