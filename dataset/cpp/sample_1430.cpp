#include <iostream>
#include <vector>
#include <cmath>

class Point {
public:
    Point(double x, double y, double z) : x(x), y(y), z(z) {}

    void translate(double dx, double dy, double dz) {
        x += dx;
        y += dy;
        z += dz;
    }

    void scale(double sx, double sy, double sz) {
        x *= sx;
        y *= sy;
        z *= sz;
    }

    void rotate_x(double angle) {
        double cos_angle = std::cos(angle);
        double sin_angle = std::sin(angle);
        double new_y = y * cos_angle - z * sin_angle;
        double new_z = y * sin_angle + z * cos_angle;
        y = new_y;
        z = new_z;
    }

    void rotate_y(double angle) {
        double cos_angle = std::cos(angle);
        double sin_angle = std::sin(angle);
        double new_x = x * cos_angle + z * sin_angle;
        double new_z = -x * sin_angle + z * cos_angle;
        x = new_x;
        z = new_z;
    }

    void rotate_z(double angle) {
        double cos_angle = std::cos(angle);
        double sin_angle = std::sin(angle);
        double new_x = x * cos_angle - y * sin_angle;
        double new_y = x * sin_angle + y * cos_angle;
        x = new_x;
        y = new_y;
    }

    double x, y, z;
};

class Transformation {
public:
    Transformation(std::vector<Point>& points) : points(points) {}

    void apply_translation(double dx, double dy, double dz) {
        for (Point& point : points) {
            point.translate(dx, dy, dz);
        }
    }

    void apply_scale(double sx, double sy, double sz) {
        for (Point& point : points) {
            point.scale(sx, sy, sz);
        }
    }

    void apply_rotation_x(double angle) {
        for (Point& point : points) {
            point.rotate_x(angle);
        }
    }

    void apply_rotation_y(double angle) {
        for (Point& point : points) {
            point.rotate_y(angle);
        }
    }

    void apply_rotation_z(double angle) {
        for (Point& point : points) {
            point.rotate_z(angle);
        }
    }

private:
    std::vector<Point>& points;
};

void main() {
    std::vector<Point> points = {Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)};
    Transformation transformation(points);
    transformation.apply_translation(1, 1, 1);
    transformation.apply_scale(2, 2, 2);
    transformation.apply_rotation_x(3.14159 / 4);
    transformation.apply_rotation_y(3.14159 / 4);
    transformation.apply_rotation_z(3.14159 / 4);
    for (const Point& point : points) {
        std::cout << '(' << point.x << ", " << point.y << ", " << point.z << ')' << std::endl;
    }
}

int main() {
    main();
    return 0;
}