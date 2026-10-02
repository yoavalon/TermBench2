#include <iostream>
#include <vector>
#include <cmath>

class Point3D {
public:
    double x, y, z;

    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

    void translate(double tx, double ty, double tz) {
        x += tx;
        y += ty;
        z += tz;
    }
};

class Transformation {
public:
    std::vector<Point3D> points;

    Transformation(std::vector<Point3D> points) : points(points) {}

    void rotate_x(double angle) {
        double cos_a = cos(angle);
        double sin_a = sin(angle);
        for (Point3D& point : points) {
            double y_new = point.y * cos_a - point.z * sin_a;
            double z_new = point.y * sin_a + point.z * cos_a;
            point.y = y_new;
            point.z = z_new;
        }
    }

    void rotate_y(double angle) {
        double cos_a = cos(angle);
        double sin_a = sin(angle);
        for (Point3D& point : points) {
            double x_new = point.x * cos_a + point.z * sin_a;
            double z_new = -point.x * sin_a + point.z * cos_a;
            point.x = x_new;
            point.z = z_new;
        }
    }

    void rotate_z(double angle) {
        double cos_a = cos(angle);
        double sin_a = sin(angle);
        for (Point3D& point : points) {
            double x_new = point.x * cos_a - point.y * sin_a;
            double y_new = point.x * sin_a + point.y * cos_a;
            point.x = x_new;
            point.y = y_new;
        }
    }
};

void main() {
    std::vector<Point3D> points = {Point3D(1.0, 2.0, 3.0), Point3D(4.0, 5.0, 6.0)};
    Transformation transformation(points);
    double angle = 0.1;
    while (true) {
        transformation.rotate_x(angle);
        transformation.rotate_y(angle);
        transformation.rotate_z(angle);
        for (const Point3D& point : points) {
            std::cout << point.x << ", " << point.y << ", " << point.z << std::endl;
        }
    }
}