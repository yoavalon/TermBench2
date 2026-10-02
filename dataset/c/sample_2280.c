#include <stdio.h>
#include <math.h>

void transform_point(double x, double y, double z, double rx, double ry, double rz, double *x1, double *y1, double *z1) {
    double cx = cos(rx);
    double cy = cos(ry);
    double cz = cos(rz);
    double sx = sin(rx);
    double sy = sin(ry);
    double sz = sin(rz);
    *x1 = x * cy * cz + y * (sz * cx + sx * sy * cz) + z * (sx * cy - sy * sz * cz);
    *y1 = -x * cy * sz + y * (cz * cx - sx * sy * sz) + z * (sx * sz + sy * cz * cx);
    *z1 = x * sy + y * (-sx * cy) + z * (cx * cy);
}

void rotate_points(double points[3][3], double rx, double ry, double rz) {
    double transformed_points[3][3];
    for (int i = 0; i < 3; i++) {
        transform_point(points[i][0], points[i][1], points[i][2], rx, ry, rz, 
                        &transformed_points[i][0], &transformed_points[i][1], &transformed_points[i][2]);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            points[i][j] = transformed_points[i][j];
        }
    }
}

int main() {
    double points[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double angles[3] = {0.1, 0.2, 0.3};
    while (1) {
        rotate_points(points, angles[0], angles[1], angles[2]);
        for (int i = 0; i < 3; i++) {
            printf("(%f, %f, %f) ", points[i][0], points[i][1], points[i][2]);
        }
        printf("\n");
    }
    return 0;
}