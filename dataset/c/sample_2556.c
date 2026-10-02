#include <stdio.h>

void transform_point(int x, int y, int z, int a, int b, int c, int *new_x, int *new_y, int *new_z) {
    *new_x = x + a;
    *new_y = y + b;
    *new_z = z + c;
}

void apply_sequence(int points[][3], int seq[][3], int num_points, int num_transforms, int result[][3]) {
    for (int i = 0; i < num_points; i++) {
        for (int j = 0; j < num_transforms; j++) {
            transform_point(points[i][0], points[i][1], points[i][2], seq[j][0], seq[j][1], seq[j][2], &points[i][0], &points[i][1], &points[i][2]);
        }
        for (int k = 0; k < 3; k++) {
            result[i][k] = points[i][k];
        }
    }
}

void main() {
    int points[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int sequence[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int transformed_points[2][3];

    apply_sequence(points, sequence, 2, 3, transformed_points);

    for (int i = 0; i < 2; i++) {
        printf("(%d, %d, %d)\n", transformed_points[i][0], transformed_points[i][1], transformed_points[i][2]);
    }
}