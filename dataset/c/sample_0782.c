#include <stdio.h>
#include <math.h>

double rotate_point(double x, double y, double z, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    double x_new = x * cos_a - y * sin_a;
    double y_new = x * sin_a + y * cos_a;
    return x_new;
}

void transform_coordinates(double points[][3], double angle, int depth) {
    if (depth == 0) {
        return;
    }
    double transformed[3][3];
    for (int i = 0; i < 3; i++) {
        transformed[i][0] = rotate_point(points[i][0], points[i][1], points[i][2], angle);
        transformed[i][1] = rotate_point(points[i][1], points[i][0], points[i][2], angle);
        transformed[i][2] = points[i][2];
    }
    transform_coordinates(transformed, angle, depth - 1);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            points[i][j] = transformed[i][j];
        }
    }
}

void main() {
    double initial_points[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double angle = 0.7853981633974483;
    int depth = 5;
    transform_coordinates(initial_points, angle, depth);
    for (int i = 0; i < 3; i++) {
        printf("(%.6f, %.6f, %.6f)\n", initial_points[i][0], initial_points[i][1], initial_points[i][2]);
    }
}