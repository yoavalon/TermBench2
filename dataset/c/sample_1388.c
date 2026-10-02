#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x, y, z;
} Point;

Point* transform_coordinates(Point* points, double matrix[3][4], int num_points) {
    Point* transformed = (Point*)malloc(num_points * sizeof(Point));
    for (int i = 0; i < num_points; i++) {
        Point point = points[i];
        transformed[i].x = matrix[0][0] * point.x + matrix[0][1] * point.y + matrix[0][2] * point.z + matrix[0][3];
        transformed[i].y = matrix[1][0] * point.x + matrix[1][1] * point.y + matrix[1][2] * point.z + matrix[1][3];
        transformed[i].z = matrix[2][0] * point.x + matrix[2][1] * point.y + matrix[2][2] * point.z + matrix[2][3];
    }
    return transformed;
}

Point* apply_transformation() {
    Point points[2] = {{1, 2, 3}, {4, 5, 6}};
    double matrix[3][4] = {{1, 0, 0, 1}, {0, 1, 0, 2}, {0, 0, 1, 3}};
    return transform_coordinates(points, matrix, 2);
}

int main() {
    Point* result = apply_transformation();
    for (int i = 0; i < 2; i++) {
        printf("(%f, %f, %f)\n", result[i].x, result[i].y, result[i].z);
    }
    free(result);
    return 0;
}