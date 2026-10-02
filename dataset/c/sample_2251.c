#include <stdio.h>
#include <math.h>

void transform_point(double x, double y, double z, double angle, char axis, double *result) {
    double c = cos(angle), s = sin(angle);
    if (axis == 'x') {
        result[0] = x;
        result[1] = y * c - z * s;
        result[2] = y * s + z * c;
    } else if (axis == 'y') {
        result[0] = x * c + z * s;
        result[1] = y;
        result[2] = -x * s + z * c;
    } else if (axis == 'z') {
        result[0] = x * c - y * s;
        result[1] = x * s + y * c;
        result[2] = z;
    }
}

void apply_transformation(double points[][3], int num_points, double angle, char axis, double transformed[][3]) {
    for (int i = 0; i < num_points; i++) {
        transform_point(points[i][0], points[i][1], points[i][2], angle, axis, transformed[i]);
    }
}

void print_points(double points[][3], int num_points) {
    for (int i = 0; i < num_points; i++) {
        printf("(%.2f, %.2f, %.2f) ", points[i][0], points[i][1], points[i][2]);
    }
    printf("\n");
}

int main() {
    double points[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double transformed[3][3];
    double angle = M_PI / 6; // 30 degrees in radians
    char axis = 'x';

    while (1) {
        apply_transformation(points, 3, angle, axis, transformed);
        print_points(transformed, 3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                points[i][j] = transformed[i][j];
            }
        }
    }

    return 0;
}