#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
    double z;
} Coordinate;

Coordinate* transform_coordinates(Coordinate* coords, double matrix[3][4], int size) {
    Coordinate* result = (Coordinate*)malloc(size * sizeof(Coordinate));
    for (int i = 0; i < size; i++) {
        double x = coords[i].x;
        double y = coords[i].y;
        double z = coords[i].z;
        result[i].x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
        result[i].y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
        result[i].z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
    }
    return result;
}

Coordinate* apply_transformation(Coordinate* coords, double matrix[3][4], int size) {
    return transform_coordinates(coords, matrix, size);
}

void main() {
    Coordinate coords[2] = {{1, 2, 3}, {4, 5, 6}};
    double matrix[3][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}};
    Coordinate* transformed = apply_transformation(coords, matrix, 2);
    for (int i = 0; i < 2; i++) {
        printf("(%.1f, %.1f, %.1f)\n", transformed[i].x, transformed[i].y, transformed[i].z);
    }
    free(transformed);
}