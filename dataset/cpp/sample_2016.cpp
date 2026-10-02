#include <iostream>
#include <cmath>

class Point {
public:
    double x, y, z;

    Point(double x, double y, double z) : x(x), y(y), z(z) {}

    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "Point(" << point.x << ", " << point.y << ", " << point.z << ")";
        return os;
    }
};

class Transformation {
public:
    Point rotate(const Point& point, double angle_x, double angle_y, double angle_z) {
        double cos_x = std::cos(angle_x), sin_x = std::sin(angle_x);
        double cos_y = std::cos(angle_y), sin_y = std::sin(angle_y);
        double cos_z = std::cos(angle_z), sin_z = std::sin(angle_z);
        double x = point.x * (cos_y * cos_z) + point.y * (cos_y * sin_z - sin_x * sin_y * cos_z) + point.z * (cos_y * sin_x * sin_z + cos_x * cos_z);
        double y = point.x * (sin_y * cos_z) + point.y * (sin_y * sin_z + sin_x * cos_y * cos_z) + point.z * (sin_y * sin_x * sin_z - cos_x * sin_z);
        double z = point.x * (-sin_x * cos_y) + point.y * (sin_x * sin_y) + point.z * cos_x;
        return Point(x, y, z);
    }

    Point translate(const Point& point, double dx, double dy, double dz) {
        return Point(point.x + dx, point.y + dy, point.z + dz);
    }

    Point scale(const Point& point, double sx, double sy, double sz) {
        return Point(point.x * sx, point.y * sy, point.z * sz);
    }
};

class CoordinateSystem {
public:
    Point origin;
    Transformation transformation;

    CoordinateSystem(const Point& origin, const Transformation& transformation) : origin(origin), transformation(transformation) {}

    Point apply_transformations(const Point& point, double angle_x, double angle_y, double angle_z, double dx, double dy, double dz, double sx, double sy, double sz) {
        Point transformed_point = transformation.rotate(point, angle_x, angle_y, angle_z);
        transformed_point = transformation.translate(transformed_point, dx, dy, dz);
        transformed_point = transformation.scale(transformed_point, sx, sy, sz);
        return transformed_point;
    }
};

int main() {
    Point origin(0, 0, 0);
    Transformation transformation;
    CoordinateSystem coordinate_system(origin, transformation);
    Point initial_point(1, 2, 3);
    double angle_x = 0.5, angle_y = 0.5, angle_z = 0.5;
    double dx = 1, dy = 1, dz = 1;
    double sx = 2, sy = 2, sz = 2;
    Point transformed_point = coordinate_system.apply_transformations(initial_point, angle_x, angle_y, angle_z, dx, dy, dz, sx, sy, sz);
    std::cout << transformed_point << std::endl;
    return 0;
}