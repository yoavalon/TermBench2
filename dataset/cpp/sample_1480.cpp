#include <iostream>
#include <vector>
#include <cmath>

class Point3D {
public:
    double x, y, z;

    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

    void translate(double dx, double dy, double dz) {
        x += dx;
        y += dy;
        z += dz;
    }

    void rotate(double angle_x, double angle_y, double angle_z) {
        double cos_x = std::cos(angle_x);
        double sin_x = std::sin(angle_x);
        double cos_y = std::cos(angle_y);
        double sin_y = std::sin(angle_y);
        double cos_z = std::cos(angle_z);
        double sin_z = std::sin(angle_z);
        double x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
        double y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
        double z_new = x * -sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
        x = x_new;
        y = y_new;
        z = z_new;
    }

    void scale(double sx, double sy, double sz) {
        x *= sx;
        y *= sy;
        z *= sz;
    }
};

void transform_point(Point3D& point, const std::vector<double>& translations, const std::vector<double>& rotations, const std::vector<double>& scales) {
    double dx = translations[0];
    double dy = translations[1];
    double dz = translations[2];
    double angle_x = rotations[0];
    double angle_y = rotations[1];
    double angle_z = rotations[2];
    double sx = scales[0];
    double sy = scales[1];
    double sz = scales[2];
    point.translate(dx, dy, dz);
    point.rotate(angle_x, angle_y, angle_z);
    point.scale(sx, sy, sz);
}

void process_points(std::vector<Point3D>& points, const std::vector<std::vector<std::vector<double>>>& transformations) {
    for (size_t i = 0; i < points.size(); ++i) {
        transform_point(points[i], transformations[i][0], transformations[i][1], transformations[i][2]);
    }
}

int main() {
    std::vector<Point3D> points = {Point3D(1, 2, 3), Point3D(4, 5, 6)};
    std::vector<std::vector<std::vector<double>>> transformations = {
        {{1, 1, 1}, {0.1, 0.2, 0.3}, {1.5, 1.5, 1.5}},
        {{-1, -1, -1}, {0.3, 0.2, 0.1}, {0.5, 0.5, 0.5}}
    };
    process_points(points, transformations);
    for (const auto& point : points) {
        std::cout << "Point(" << point.x << ", " << point.y << ", " << point.z << ")\n";
    }
    return 0;
}