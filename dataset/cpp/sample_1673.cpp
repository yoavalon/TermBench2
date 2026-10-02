#include <cmath>

double transform_coordinates(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
    double cx = std::cos(angle_x);
    double cy = std::cos(angle_y);
    double cz = std::cos(angle_z);
    double sx = std::sin(angle_x);
    double sy = std::sin(angle_y);
    double sz = std::sin(angle_z);
    double x1 = x * cy * cz - y * sz + z * sy * cz;
    double y1 = x * cy * sz + y * cz + z * sy * sz;
    double z1 = -x * sx * cy + z * cx;
    return {x1, y1, z1};
}

void apply_rotation() {
    double x = 1.0, y = 1.0, z = 1.0;
    double angle_x = M_PI / 4, angle_y = M_PI / 4, angle_z = M_PI / 4;
    while (true) {
        auto [x1, y1, z1] = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
        x = x1;
        y = y1;
        z = z1;
    }
}

int main() {
    apply_rotation();
    return 0;
}