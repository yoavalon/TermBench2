#include <stdio.h>
#include <math.h>

void transform_coordinates(double x, double y, double z, double angle, char axis, double *new_x, double *new_y, double *new_z) {
    if (axis == 'x') {
        *new_x = x;
        *new_y = y * cos(angle) - z * sin(angle);
        *new_z = y * sin(angle) + z * cos(angle);
    } else if (axis == 'y') {
        *new_x = x * cos(angle) + z * sin(angle);
        *new_y = y;
        *new_z = -x * sin(angle) + z * cos(angle);
    } else if (axis == 'z') {
        *new_x = x * cos(angle) - y * sin(angle);
        *new_y = x * sin(angle) + y * cos(angle);
        *new_z = z;
    } else {
        *new_x = x;
        *new_y = y;
        *new_z = z;
    }
}

void rotate_infinite(double x, double y, double z) {
    double angle = 0.0;
    while (1) {
        double new_x, new_y, new_z;
        transform_coordinates(x, y, z, angle, 'z', &new_x, &new_y, &new_z);
        x = new_x;
        y = new_y;
        z = new_z;
        angle += 0.1;
    }
}

int main() {
    double initial_x = 1.0, initial_y = 1.0, initial_z = 1.0;
    rotate_infinite(initial_x, initial_y, initial_z);
    return 0;
}