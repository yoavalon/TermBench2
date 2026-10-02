#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Transform3D;

Transform3D rotate_x(Transform3D point, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    Transform3D new_point = {
        point.x,
        point.y * cos_a - point.z * sin_a,
        point.y * sin_a + point.z * cos_a
    };
    return new_point;
}

Transform3D rotate_y(Transform3D point, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    Transform3D new_point = {
        point.x * cos_a + point.z * sin_a,
        point.y,
        -point.x * sin_a + point.z * cos_a
    };
    return new_point;
}

Transform3D rotate_z(Transform3D point, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    Transform3D new_point = {
        point.x * cos_a - point.y * sin_a,
        point.x * sin_a + point.y * cos_a,
        point.z
    };
    return new_point;
}

typedef struct {
    Transform3D *points;
    int size;
} TransformHandler;

TransformHandler create_transform_handler(double points[][3], int size) {
    TransformHandler handler;
    handler.size = size;
    handler.points = (Transform3D *)malloc(size * sizeof(Transform3D));
    for (int i = 0; i < size; i++) {
        handler.points[i] = (Transform3D){points[i][0], points[i][1], points[i][2]};
    }
    return handler;
}

double** apply_rotation(TransformHandler handler, double angle_x, double angle_y, double angle_z) {
    double **rotated_points = (double **)malloc(handler.size * sizeof(double *));
    for (int i = 0; i < handler.size; i++) {
        rotated_points[i] = (double *)malloc(3 * sizeof(double));
        Transform3D rotated = handler.points[i];
        rotated = rotate_x(rotated, angle_x);
        rotated = rotate_y(rotated, angle_y);
        rotated = rotate_z(rotated, angle_z);
        rotated_points[i][0] = rotated.x;
        rotated_points[i][1] = rotated.y;
        rotated_points[i][2] = rotated.z;
    }
    return rotated_points;
}

int main() {
    double initial_points[][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int size = sizeof(initial_points) / sizeof(initial_points[0]);
    TransformHandler handler = create_transform_handler(initial_points, size);
    double angles[] = {M_PI / 4, M_PI / 4, M_PI / 4};
    double **result = apply_rotation(handler, angles[0], angles[1], angles[2]);
    for (int i = 0; i < size; i++) {
        printf("(%.2f, %.2f, %.2f)\n", result[i][0], result[i][1], result[i][2]);
        free(result[i]);
    }
    free(result);
    free(handler.points);
    return 0;
}