#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>

class CoordinateTransform {
public:
    CoordinateTransform(double x, double y, double z) : x(x), y(y), z(z) {}

    void translate(double dx, double dy, double dz) {
        x += dx;
        y += dy;
        z += dz;
    }

    void rotate_x(double angle) {
        double rad = angle * M_PI / 180.0;
        double new_y = y * cos(rad) - z * sin(rad);
        double new_z = y * sin(rad) + z * cos(rad);
        y = new_y;
        z = new_z;
    }

    void rotate_y(double angle) {
        double rad = angle * M_PI / 180.0;
        double new_x = x * cos(rad) + z * sin(rad);
        double new_z = -x * sin(rad) + z * cos(rad);
        x = new_x;
        z = new_z;
    }

    void rotate_z(double angle) {
        double rad = angle * M_PI / 180.0;
        double new_x = x * cos(rad) - y * sin(rad);
        double new_y = x * sin(rad) + y * cos(rad);
        x = new_x;
        y = new_y;
    }

private:
    double x, y, z;
};

void transform_sequence(CoordinateTransform& coord, const std::vector<std::tuple<std::string, double, double, double>>& sequence) {
    for (const auto& action : sequence) {
        const std::string& action_type = std::get<0>(action);
        if (action_type == "translate") {
            coord.translate(std::get<1>(action), std::get<2>(action), std::get<3>(action));
        } else if (action_type == "rotate_x") {
            coord.rotate_x(std::get<1>(action));
        } else if (action_type == "rotate_y") {
            coord.rotate_y(std::get<1>(action));
        } else if (action_type == "rotate_z") {
            coord.rotate_z(std::get<1>(action));
        }
    }
}

int main() {
    CoordinateTransform coord(1, 2, 3);
    std::vector<std::tuple<std::string, double, double, double>> sequence = {
        {"translate", 1, 1, 1},
        {"rotate_x", 45},
        {"rotate_y", 45},
        {"rotate_z", 45},
        {"translate", -1, -1, -1}
    };
    while (true) {
        transform_sequence(coord, sequence);
        std::cout << "(" << coord.x << ", " << coord.y << ", " << coord.z << ")" << std::endl;
    }
    return 0;
}