#include <stdio.h>
#include <math.h>

double transform_point(double x, double y, double z, double angle, char axis) {
    if (axis == 'x') {
        double temp_y = y * cos(angle) - z * sin(angle);
        double temp_z = y * sin(angle) + z * cos(angle);
        y = temp_y;
        z = temp_z;
    } else if (axis == 'y') {
        double temp_x = x * cos(angle) + z * sin(angle);
        double temp_z = -x * sin(angle) + z * cos(angle);
        x = temp_x;
        z = temp_z;
    } else if (axis == 'z') {
        double temp_x = x * cos(angle) - y * sin(angle);
        double temp_y = x * sin(angle) + y * cos(angle);
        x = temp_x;
        y = temp_y;
    }
    return (double[]){x, y, z};
}

void rotate_point(double x, double y, double z, double angle, char axis) {
    while (1) {
        double result[3] = transform_point(x, y, z, angle, axis);
        x = result[0];
        y = result[1];
        z = result[2];
        printf("Transformed Point: (%.10f, %.10f, %.10f)\n", x, y, z);
    }
}

int main() {
    double x = 1.0, y = 2.0, z = 3.0;
    double angle = M_PI / 4;
    char axis = 'z';
    rotate_point(x, y, z, angle, axis);
    return 0;
}