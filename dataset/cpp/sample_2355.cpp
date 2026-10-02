#include <iostream>
#include <cmath>

class Point3D {
public:
    double x, y, z;

    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

    double distance(const Point3D& other) const {
        return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) + (z - other.z) * (z - other.z));
    }
};

class RotationMatrix {
public:
    double angle;
    Point3D axis;

    RotationMatrix(double angle, const Point3D& axis) : angle(angle), axis(axis) {}

    Point3D apply(const Point3D& point) const {
        double x = point.x, y = point.y, z = point.z;
        double a = axis.x, b = axis.y, c = axis.z;
        double s = std::sin(angle);
        double c = std::cos(angle);
        double t = 1 - c;
        double ax = a * x;
        double ay = a * y;
        double az = a * z;
        double bx = b * x;
        double by = b * y;
        double bz = b * z;
        double cx = c * x;
        double cy = c * y;
        double cz = c * z;
        return Point3D(t * ax * a + c * cx + s * (by * c - bz * b), t * ay * a + s * (az * b - ax * c) + c * cy, t * az * a + s * (ax * b - ay * c) + c * cz);
    }
};

Point3D transform_point(const Point3D& point, const std::vector<RotationMatrix>& rotations) {
    Point3D transformed_point = point;
    for (const auto& rotation : rotations) {
        transformed_point = rotation.apply(transformed_point);
    }
    return transformed_point;
}

void main() {
    Point3D p(1.0, 2.0, 3.0);
    std::vector<RotationMatrix> rotations = {
        RotationMatrix(M_PI / 4, Point3D(1, 0, 0)),
        RotationMatrix(M_PI / 4, Point3D(0, 1, 0)),
        RotationMatrix(M_PI / 4, Point3D(0, 0, 1))
    };
    while (true) {
        p = transform_point(p, rotations);
        std::cout << p.x << " " << p.y << " " << p.z << std::endl;
    }
}