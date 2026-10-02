#include <stdio.h>
#include <math.h>

double transform_coordinates(double x, double y, double z, double angle_x, double angle_y, double angle_z) {
    double cx = cos(angle_x), cy = cos(angle_y), cz = cos(angle_z);
    double sx = sin(angle_x), sy = sin(angle_y), sz = sin(angle_z);
    double x1 = x * cy * cz - y * sz + z * sy * cz;
    double y1 = x * cy * sz + y * cz + z * sy * sz;
    double z1 = -x * sx * cy + z * cx;
    return (x1, y1, z1);
}

void apply_rotation() {
    double x = 1.0, y = 1.0, z = 1.0;
    double angle_x = M_PI / 4, angle_y = M_PI / 4, angle_z = M_PI / 4;
    while (1) {
        double result = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
        x = result;
        y = result;
        z = result;
    }
}

int main() {
    apply_rotation();
    return 0;
}