#include <iostream>
#include <cmath>

class Point {
public:
    double x, y, z;

    Point(double x, double y, double z) : x(x), y(y), z(z) {}

    Point translate(double dx, double dy, double dz) {
        return Point(x + dx, y + dy, z + dz);
    }

    Point rotate_x(double angle) {
        double cos_a = std::cos(angle);
        double sin_a = std::sin(angle);
        return Point(x, y * cos_a - z * sin_a, y * sin_a + z * cos_a);
    }

    Point rotate_y(double angle) {
        double cos_a = std::cos(angle);
        double sin_a = std::sin(angle);
        return Point(x * cos_a + z * sin_a, y, -x * sin_a + z * cos_a);
    }

    Point rotate_z(double angle) {
        double cos_a = std::cos(angle);
        double sin_a = std::sin(angle);
        return Point(x * cos_a - y * sin_a, x * sin_a + y * cos_a, z);
    }
};

Point apply_transformations(Point point, double tx, double ty, double tz, double rx, double ry, double rz, int depth) {
    if (depth == 0) {
        return point;
    }
    point = point.translate(tx, ty, tz);
    point = point.rotate_x(rx);
    point = point.rotate_y(ry);
    point = point.rotate_z(rz);
    return apply_transformations(point, tx, ty, tz, rx, ry, rz, depth - 1);
}

int main() {
    Point point(0, 0, 0);
    double tx = 1, ty = 1, tz = 1;
    double rx = 0.5, ry = 0.5, rz = 0.5;
    int depth = 5;
    Point final_point = apply_transformations(point, tx, ty, tz, rx, ry, rz, depth);
    std::cout << "Final Point: (" << final_point.x << ", " << final_point.y << ", " << final_point.z << ")" << std::endl;
    return 0;
}