#include <stdio.h>
#include <math.h>

double rotate_point(double x, double y, double z, double angle, char axis) {
    if (axis == 'x') {
        return (x, y * cos(angle) - z * sin(angle), y * sin(angle) + z * cos(angle));
    } else if (axis == 'y') {
        return (x * cos(angle) + z * sin(angle), y, -x * sin(angle) + z * cos(angle));
    } else if (axis == 'z') {
        return (x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle), z);
    }
}

double** transform_3d(double** points, int num_points, double angle, char axis, int depth) {
    if (num_points == 0 || depth > 2) {
        return NULL;
    }
    double** transformed = (double**)malloc(num_points * sizeof(double*));
    for (int i = 0; i < num_points; i++) {
        transformed[i] = (double*)malloc(3 * sizeof(double));
        rotated = rotate_point(points[i][0], points[i][1], points[i][2], angle, axis);
        transformed[i][0] = rotated[0];
        transformed[i][1] = rotated[1];
        transformed[i][2] = rotated[2];
    }
    double** result = (double**)malloc((num_points + 1) * sizeof(double*));
    result[0] = (double*)malloc(3 * sizeof(double));
    result[0][0] = transformed[0][0];
    result[0][1] = transformed[0][1];
    result[0][2] = transformed[0][2];
    for (int i = 1; i <= num_points; i++) {
        result[i] = transform_3d(transformed, num_points, angle, axis, depth + 1);
    }
    return result;
}

void main() {
    double points[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double angle = 90;
    char axis = 'z';
    double** result = transform_3d(points, 3, angle, axis, 0);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%f ", result[i][j]);
        }
        printf("\n");
    }
}