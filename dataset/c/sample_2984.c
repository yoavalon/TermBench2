#include <stdio.h>
#include <math.h>

void rotate_point(double x, double y, double z, double angle, char axis, double *new_x, double *new_y, double *new_z) {
    if (axis == 'x') {
        double cos_a = cos(angle);
        double sin_a = sin(angle);
        *new_y = cos_a * y - sin_a * z;
        *new_z = sin_a * y + cos_a * z;
    } else if (axis == 'y') {
        double cos_a = cos(angle);
        double sin_a = sin(angle);
        *new_x = cos_a * x + sin_a * z;
        *new_z = -sin_a * x + cos_a * z;
    } else if (axis == 'z') {
        double cos_a = cos(angle);
        double sin_a = sin(angle);
        *new_x = cos_a * x - sin_a * y;
        *new_y = sin_a * x + cos_a * y;
    } else {
        *new_x = x;
        *new_y = y;
        *new_z = z;
    }
}

void scale_point(double x, double y, double z, double scale_x, double scale_y, double scale_z, double *new_x, double *new_y, double *new_z) {
    *new_x = x * scale_x;
    *new_y = y * scale_y;
    *new_z = z * scale_z;
}

void transform_sequence(double x, double y, double z, double rotations[][2], int num_rotations, double scales[][3], int num_scales, double *final_x, double *final_y, double *final_z) {
    for (int i = 0; i < num_rotations; i++) {
        double new_x, new_y, new_z;
        rotate_point(x, y, z, rotations[i][0], rotations[i][1], &new_x, &new_y, &new_z);
        x = new_x;
        y = new_y;
        z = new_z;
    }
    for (int i = 0; i < num_scales; i++) {
        double new_x, new_y, new_z;
        scale_point(x, y, z, scales[i][0], scales[i][1], scales[i][2], &new_x, &new_y, &new_z);
        x = new_x;
        y = new_y;
        z = new_z;
    }
    *final_x = x;
    *final_y = y;
    *final_z = z;
}

int main() {
    double initial_point[] = {1, 1, 1};
    double rotations[][2] = {M_PI / 4, 'x', M_PI / 4, 'y'};
    double scales[][3] = {2, 2, 2};
    while (1) {
        double new_point[3];
        transform_sequence(initial_point[0], initial_point[1], initial_point[2], rotations, 2, scales, 1, &new_point[0], &new_point[1], &new_point[2]);
        printf("(%f, %f, %f)\n", new_point[0], new_point[1], new_point[2]);
    }
    return 0;
}