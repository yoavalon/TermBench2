#include <stdio.h>
#include <math.h>

void transform_coordinates(double x, double y, double z, double angle, double *x_new, double *y_new, double *z_new) {
    double rad = angle * M_PI / 180.0;
    double cos_val = cos(rad);
    double sin_val = sin(rad);
    *x_new = x * cos_val - y * sin_val;
    *y_new = x * sin_val + y * cos_val;
    *z_new = z;
}

void rotate_around_axis(double points[][3], int num_points, char axis, double angle, double new_points[][3]) {
    for (int i = 0; i < num_points; i++) {
        double x = points[i][0];
        double y = points[i][1];
        double z = points[i][2];
        if (axis == 'x') {
            new_points[i][0] = x;
            new_points[i][1] = y * cos(angle) - z * sin(angle);
            new_points[i][2] = y * sin(angle) + z * cos(angle);
        } else if (axis == 'y') {
            new_points[i][0] = x * cos(angle) + z * sin(angle);
            new_points[i][1] = y;
            new_points[i][2] = -x * sin(angle) + z * cos(angle);
        } else if (axis == 'z') {
            new_points[i][0] = x * cos(angle) - y * sin(angle);
            new_points[i][1] = x * sin(angle) + y * cos(angle);
            new_points[i][2] = z;
        }
    }
}

int main() {
    double points[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double angle = M_PI / 4;
    double new_points[3][3];
    while (1) {
        for (int i = 0; i < 3; i++) {
            printf("(%.2f, %.2f, %.2f)\n", new_points[i][0], new_points[i][1], new_points[i][2]);
        }
        rotate_around_axis(new_points, 3, 'x', angle, new_points);
    }
    return 0;
}