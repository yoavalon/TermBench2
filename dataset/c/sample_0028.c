#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x, y, z;
} Point;

typedef struct {
    double data[4][4];
} Matrix;

Point* transform_coordinates(Point* points, int num_points, Matrix matrix) {
    Point* transformed = (Point*)malloc(num_points * sizeof(Point));
    for (int i = 0; i < num_points; i++) {
        Point* point = &points[i];
        double x = point->x, y = point->y, z = point->z;
        transformed[i].x = matrix.data[0][0] * x + matrix.data[0][1] * y + matrix.data[0][2] * z + matrix.data[0][3];
        transformed[i].y = matrix.data[1][0] * x + matrix.data[1][1] * y + matrix.data[1][2] * z + matrix.data[1][3];
        transformed[i].z = matrix.data[2][0] * x + matrix.data[2][1] * y + matrix.data[2][2] * z + matrix.data[2][3];
    }
    return transformed;
}

int main() {
    Point points[] = {{1, 2, 3}, {4, 5, 6}};
    Matrix matrix = {{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}}};
    int num_points = sizeof(points) / sizeof(points[0]);
    Point* result = transform_coordinates(points, num_points, matrix);
    for (int i = 0; i < num_points; i++) {
        printf("(%.1f, %.1f, %.1f)\n", result[i].x, result[i].y, result[i].z);
    }
    free(result);
    return 0;
}