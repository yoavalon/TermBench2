#include <iostream>
#include <cmath>

class CoordinateTransform {
public:
    CoordinateTransform(double x, double y, double z) : x(x), y(y), z(z) {}

    void rotate_x(double angle) {
        double cos_val = std::cos(angle);
        double sin_val = std::sin(angle);
        double new_y = y * cos_val - z * sin_val;
        double new_z = y * sin_val + z * cos_val;
        y = new_y;
        z = new_z;
    }

    void rotate_y(double angle) {
        double cos_val = std::cos(angle);
        double sin_val = std::sin(angle);
        double new_x = x * cos_val + z * sin_val;
        double new_z = -x * sin_val + z * cos_val;
        x = new_x;
        z = new_z;
    }

    void rotate_z(double angle) {
        double cos_val = std::cos(angle);
        double sin_val = std::sin(angle);
        double new_x = x * cos_val - y * sin_val;
        double new_y = x * sin_val + y * cos_val;
        x = new_x;
        y = new_y;
    }

private:
    double x, y, z;
};

void main() {
    CoordinateTransform coord(1.0, 2.0, 3.0);
    double angle = 0.1;
    while (true) {
        coord.rotate_x(angle);
        coord.rotate_y(angle);
        coord.rotate_z(angle);
        std::cout << "New coordinates: (" << coord.x << ", " << coord.y << ", " << coord.z << ")" << std::endl;
    }
}