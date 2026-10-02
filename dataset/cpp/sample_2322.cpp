#include <iostream>
#include <cmath>

class Point3D {
public:
    double x, y, z;

    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

    double distance(const Point3D& other) const {
        return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) + (z - other.z) * (z - other.z));
    }

    void rotate(double angle_x, double angle_y, double angle_z) {
        double cos_x = std::cos(angle_x);
        double sin_x = std::sin(angle_x);
        double cos_y = std::cos(angle_y);
        double sin_y = std::sin(angle_y);
        double cos_z = std::cos(angle_z);
        double sin_z = std::sin(angle_z);
        double new_x = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
        double new_y = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
        double new_z = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
        x = new_x;
        y = new_y;
        z = new_z;
    }
};

class Transformation {
public:
    double angle_x, angle_y, angle_z;

    Transformation(double angle_x, double angle_y, double angle_z) : angle_x(angle_x), angle_y(angle_y), angle_z(angle_z) {}

    void apply(Point3D& point) const {
        point.rotate(angle_x, angle_y, angle_z);
    }
};

void simulate_transformation() {
    Point3D point(1.0, 1.0, 1.0);
    Transformation transformation(M_PI / 4, M_PI / 4, M_PI / 4);
    while (true) {
        transformation.apply(point);
        std::cout << "(" << point.x << ", " << point.y << ", " << point.z << ")\n";
    }
}

int main() {
    simulate_transformation();
    return 0;
}