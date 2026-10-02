#include <stdio.h>

typedef struct {
    float x, y, z;
} Coordinate;

Coordinate* transform_coordinates(Coordinate* coords, float matrix[4][4], int num_coords) {
    Coordinate* result = (Coordinate*)malloc(num_coords * sizeof(Coordinate));
    for (int i = 0; i < num_coords; i++) {
        float x = coords[i].x, y = coords[i].y, z = coords[i].z;
        result[i].x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
        result[i].y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
        result[i].z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
    }
    return result;
}

int main() {
    float matrix[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    Coordinate coords[] = {{1, 2, 3}, {4, 5, 6}};
    int num_coords = sizeof(coords) / sizeof(coords[0]);
    Coordinate* new_coords = transform_coordinates(coords, matrix, num_coords);
    for (int i = 0; i < num_coords; i++) {
        printf("(%.1f, %.1f, %.1f)\n", new_coords[i].x, new_coords[i].y, new_coords[i].z);
    }
    free(new_coords);
    return 0;
}