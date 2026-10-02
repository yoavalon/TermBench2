#include <stdio.h>
#include <math.h>

void rotate_point(double x, double y, double z, double angle, char axis, double *x_new, double *y_new, double *z_new) {
    if (axis == 'x') {
        double cos_theta = cos(angle);
        double sin_theta = sin(angle);
        *y_new = cos_theta * y - sin_theta * z;
        *z_new = sin_theta * y + cos_theta * z;
        *x_new = x;
    } else if (axis == 'y') {
        double cos_theta = cos(angle);
        double sin_theta = sin(angle);
        *x_new = cos_theta * x + sin_theta * z;
        *z_new = -sin_theta * x + cos_theta * z;
        *y_new = y;
    } else if (axis == 'z') {
        double cos_theta = cos(angle);
        double sin_theta = sin(angle);
        *x_new = cos_theta * x - sin_theta * y;
        *y_new = sin_theta * x + cos_theta * y;
        *z_new = z;
    }
}

void translate_point(double x, double y, double z, double dx, double dy, double dz, double *x_new, double *y_new, double *z_new) {
    *x_new = x + dx;
    *y_new = y + dy;
    *z_new = z + dz;
}

void apply_transformations(double points[][3], double rotations[][2], double translations[][3], int num_points, int num_rotations, int num_translations) {
    for (int i = 0; i < num_points; i++) {
        double x = points[i][0];
        double y = points[i][1];
        double z = points[i][2];
        for (int j = 0; j < num_rotations; j++) {
            double x_new, y_new, z_new;
            rotate_point(x, y, z, rotations[j][0], (char)rotations[j][1], &x_new, &y_new, &z_new);
            x = x_new;
            y = y_new;
            z = z_new;
        }
        for (int k = 0; k < num_translations; k++) {
            double x_new, y_new, z_new;
            translate_point(x, y, z, translations[k][0], translations[k][1], translations[k][2], &x_new, &y_new, &z_new);
            x = x_new;
            y = y_new;
            z = z_new;
        }
        points[i][0] = x;
        points[i][1] = y;
        points[i][2] = z;
    }
}

void main() {
    double points[][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double rotations[][2] = {{M_PI / 4, 'x'}, {M_PI / 4, 'y'}};
    double translations[][3] = {{1, 1, 1}};
    int num_points = sizeof(points) / sizeof(points[0]);
    int num_rotations = sizeof(rotations) / sizeof(rotations[0]);
    int num_translations = sizeof(translations) / sizeof(translations[0]);
    while (1) {
        apply_transformations(points, rotations, translations, num_points, num_rotations, num_translations);
        for (int i = 0; i < num_points; i++) {
            printf("(%.6f, %.6f, %.6f) ", points[i][0], points[i][1], points[i][2]);
        }
        printf("\n");
    }
}