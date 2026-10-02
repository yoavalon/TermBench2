#include <stdio.h>

void transform_coordinates(int coords[3], int rotation_matrix[9], int new_coords[3]) {
    int x = coords[0], y = coords[1], z = coords[2];
    int a = rotation_matrix[0], b = rotation_matrix[1], c = rotation_matrix[2];
    int d = rotation_matrix[3], e = rotation_matrix[4], f = rotation_matrix[5];
    int g = rotation_matrix[6], h = rotation_matrix[7], i = rotation_matrix[8];
    new_coords[0] = a * x + b * y + c * z;
    new_coords[1] = d * x + e * y + f * z;
    new_coords[2] = g * x + h * y + i * z;
}

int main() {
    int coords[] = {1, 2, 3};
    int rotation_matrix[] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    int new_coords[3];
    transform_coordinates(coords, rotation_matrix, new_coords);
    printf("(%d, %d, %d)\n", new_coords[0], new_coords[1], new_coords[2]);
    return 0;
}