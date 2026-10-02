#include <iostream>
#include <vector>
#include <cmath>
#include <string>

class Point3D {
public:
    double x, y, z;

    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

    Point3D translate(double dx, double dy, double dz) {
        return Point3D(x + dx, y + dy, z + dz);
    }

    Point3D rotate_x(double angle) {
        double cos_a = cos(angle);
        double sin_a = sin(angle);
        return Point3D(x, y * cos_a - z * sin_a, y * sin_a + z * cos_a);
    }

    Point3D rotate_y(double angle) {
        double cos_a = cos(angle);
        double sin_a = sin(angle);
        return Point3D(x * cos_a + z * sin_a, y, -x * sin_a + z * cos_a);
    }

    Point3D rotate_z(double angle) {
        double cos_a = cos(angle);
        double sin_a = sin(angle);
        return Point3D(x * cos_a - y * sin_a, x * sin_a + y * cos_a, z);
    }

    std::string repr() {
        return "Point3D(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
    }
};

Point3D transform_sequence(Point3D point, const std::vector<std::pair<std::string, std::vector<double>>>& operations, int index = 0) {
    if (index == operations.size()) {
        return point;
    }
    const auto& operation = operations[index];
    if (operation.first == "translate") {
        point = point.translate(operation.second[0], operation.second[1], operation.second[2]);
    } else if (operation.first == "rotate_x") {
        point = point.rotate_x(operation.second[0]);
    } else if (operation.first == "rotate_y") {
        point = point.rotate_y(operation.second[0]);
    } else if (operation.first == "rotate_z") {
        point = point.rotate_z(operation.second[0]);
    }
    return transform_sequence(point, operations, index + 1);
}

void main() {
    Point3D point(1, 2, 3);
    std::vector<std::pair<std::string, std::vector<double>>> operations = {
        {"translate", {1, 1, 1}},
        {"rotate_x", {0.785398}},
        {"rotate_y", {0.785398}},
        {"rotate_z", {0.785398}},
        {"translate", {-1, -1, -1}}
    };
    Point3D final_point = transform_sequence(point, operations);
    std::cout << final_point.repr() << std::endl;
}

int main() {
    main();
    return 0;
}