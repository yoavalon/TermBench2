#include <iostream>
#include <cmath>

std::tuple<double, double, double> rotate_point(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
    double rad_x = std::acos(-1) * angle_x / 180.0;
    double rad_y = std::acos(-1) * angle_y / 180.0;
    double rad_z = std::acos(-1) * angle_z / 180.0;
    double x_rot = x * std::cos(rad_y) * std::cos(rad_z) - y * std::sin(rad_z) + z * std::sin(rad_y) * std::cos(rad_z);
    double y_rot = x * std::cos(rad_y) * std::sin(rad_z) + y * std::cos(rad_z) + z * std::sin(rad_y) * std::sin(rad_z);
    double z_rot = -x * std::sin(rad_y) + z * std::cos(rad_y);
    double x_new = x_rot * std::cos(rad_z) - y_rot * std::sin(rad_z);
    double y_new = x_rot * std::sin(rad_z) + y_rot * std::cos(rad_z);
    double z_new = z_rot;
    x_new = x_new * std::cos(rad_x) + z_new * std::sin(rad_x);
    z_new = -x_new * std::sin(rad_x) + z_new * std::cos(rad_x);
    return std::make_tuple(x_new, y_new, z_new);
}

std::tuple<double, double, double> translate_point(double x, double y, double z, double tx, double ty, double tz) {
    return std::make_tuple(x + tx, y + ty, z + tz);
}

std::tuple<double, double, double> scale_point(double x, double y, double z, double sx, double sy, double sz) {
    return std::make_tuple(x * sx, y * sy, z * sz);
}

void main() {
    double x = 0, y = 0, z = 0;
    double angle_x = 0, angle_y = 0, angle_z = 0;
    double tx = 0, ty = 0, tz = 0;
    double sx = 1, sy = 1, sz = 1;
    while (true) {
        std::tie(x, y, z) = rotate_point(x, y, z, angle_x, angle_y, angle_z);
        std::tie(x, y, z) = translate_point(x, y, z, tx, ty, tz);
        std::tie(x, y, z) = scale_point(x, y, z, sx, sy, sz);
        angle_x += 1;
        angle_y += 1;
        angle_z += 1;
        tx += 0.1;
        ty += 0.1;
        tz += 0.1;
        sx += 0.01;
        sy += 0.01;
        sz += 0.01;
    }
}

int main() {
    main();
    return 0;
}