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
        double x = points[i].x, y = points[i].y, z = points[i].z;
        transformed[i].x = matrix.data[0][0] * x + matrix.data[0][1] * y + matrix.data[0][2] * z + matrix.data[0][3];
        transformed[i].y = matrix.data[1][0] * x + matrix.data[1][1] * y + matrix.data[1][2] * z + matrix.data[1][3];
        transformed[i].z = matrix.data[2][0] * x + matrix.data[2][1] * y + matrix.data[2][2] * z + matrix.data[2][3];
    }
    return transformed;
}

int main() {
    Matrix transformation_matrix;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            transformation_matrix.data[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    Point points_list[] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    int num_points = sizeof(points_list) / sizeof(points_list[0]);

    Point* result = transform_coordinates(points_list, num_points, transformation_matrix);

    for (int i = 0; i < num_points; i++) {
        printf("(%.1f, %.1f, %.1f)\n", result[i].x, result[i].y, result[i].z);
    }

    free(result);
    return 0;
}