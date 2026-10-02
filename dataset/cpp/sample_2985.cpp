#include <iostream>
#include <cmath>
#include <vector>
#include <string>

class Point {
public:
    double x, y, z;

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

    void rotate(double rx, double ry, double rz) {
        double cos_rx = std::cos(rx), sin_rx = std::sin(rx);
        double cos_ry = std::cos(ry), sin_ry = std::sin(ry);
        double cos_rz = std::cos(rz), sin_rz = std::sin(rz);
        double new_x = cos_ry * (cos_rz * x + sin_rz * y) - sin_ry * z;
        double new_y = sin_rx * (cos_ry * z + sin_ry * (cos_rz * x + sin_rz * y)) + cos_rx * (cos_rz * x + sin_rz * y);
        double new_z = cos_rx * (cos_ry * z + sin_ry * (cos_rz * x + sin_rz * y)) - sin_rx * (cos_rz * x + sin_rz * y);
        x = new_x;
        y = new_y;
        z = new_z;
    }
};

void transform_sequence(Point &point, const std::vector<std::pair<std::string, std::vector<double>>>& transformations) {
    for (const auto& transform : transformations) {
        const std::string& transform_type = transform.first;
        const std::vector<double>& params = transform.second;
        if (transform_type == "translate") {
            point.translate(params[0], params[1], params[2]);
        } else if (transform_type == "scale") {
            point.scale(params[0], params[1], params[2]);
        } else if (transform_type == "rotate") {
            point.rotate(params[0], params[1], params[2]);
        }
    }
}

int main() {
    Point p(1, 0, 0);
    std::vector<std::pair<std::string, std::vector<double>>> transformations = {
        {"translate", {1, 1, 1}},
        {"scale", {2, 2, 2}},
        {"rotate", {0.5, 0.5, 0.5}},
        {"translate", {1, 1, 1}},
        {"scale", {0.5, 0.5, 0.5}},
        {"rotate", {-0.5, -0.5, -0.5}}
    };
    while (true) {
        transform_sequence(p, transformations);
        std::cout << "Current position: (" << p.x << ", " << p.y << ", " << p.z << ")" << std::endl;
    }
    return 0;
}