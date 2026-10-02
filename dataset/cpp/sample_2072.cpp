#include <iostream>
#include <cmath>

class Point3D {
public:
    double x, y, z;

    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

    Point3D translate(double dx, double dy, double dz) {
        return Point3D(x + dx, y + dy, z + dz);
    }

    Point3D scale(double sx, double sy, double sz) {
        return Point3D(x * sx, y * sy, z * sz);
    }

    Point3D rotate_x(double angle) {
        double c = cos(angle);
        double s = sin(angle);
        return Point3D(x, y * c - z * s, y * s + z * c);
    }

    Point3D rotate_y(double angle) {
        double c = cos(angle);
        double s = sin(angle);
        return Point3D(x * c + z * s, y, -x * s + z * c);
    }

    Point3D rotate_z(double angle) {
        double c = cos(angle);
        double s = sin(angle);
        return Point3D(x * c - y * s, x * s + y * c, z);
    }
};

class Transformation {
public:
    Point3D point;

    Transformation(Point3D point) : point(point) {}

    void apply_transformations(const std::vector<std::tuple<double, double, double>>& translations,
                              const std::vector<std::tuple<double, double, double>>& scalings,
                              const std::vector<double>& rotations) {
        for (const auto& [dx, dy, dz] : translations) {
            point = point.translate(dx, dy, dz);
        }
        for (const auto& [sx, sy, sz] : scalings) {
            point = point.scale(sx, sy, sz);
        }
        for (double angle : rotations) {
            point = point.rotate_x(angle);
            point = point.rotate_y(angle);
            point = point.rotate_z(angle);
        }
    }

    std::tuple<double, double, double> get_final_position() {
        return std::make_tuple(point.x, point.y, point.z);
    }
};

int main() {
    Point3D initial_point(1.0, 2.0, 3.0);
    Transformation transformations(initial_point);
    std::vector<std::tuple<double, double, double>> translations = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}};
    std::vector<std::tuple<double, double, double>> scalings = {{2.0, 2.0, 2.0}};
    std::vector<double> rotations = {0.785398163};
    transformations.apply_transformations(translations, scalings, rotations);
    auto final_position = transformations.get_final_position();
    std::cout << std::get<0>(final_position) << ", " << std::get<1>(final_position) << ", " << std::get<2>(final_position) << std::endl;
    return 0;
}