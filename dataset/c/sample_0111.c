#include <stdio.h>

void transform_point(float x, float y, float z, float a, float b, float c, float *x_new, float *y_new, float *z_new) {
    *x_new = a * x + b * y + c * z;
    *y_new = a * y + b * z + c * x;
    *z_new = a * z + b * x + c * y;
}

void process_points(float points[][3], int num_points, float a, float b, float c, float transformed_points[][3]) {
    for (int i = 0; i < num_points; i++) {
        transform_point(points[i][0], points[i][1], points[i][2], a, b, c, &transformed_points[i][0], &transformed_points[i][1], &transformed_points[i][2]);
    }
}

int main() {
    float points[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    float a = 1, b = 0, c = 0;
    float transformed_points[3][3];
    process_points(points, 3, a, b, c, transformed_points);
    for (int i = 0; i < 3; i++) {
        printf("(%.1f, %.1f, %.1f) ", transformed_points[i][0], transformed_points[i][1], transformed_points[i][2]);
    }
    printf("\n");
    return 0;
}