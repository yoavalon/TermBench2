#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

double rotate_point(double point[3], double angle, double result[3]) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    double rotation_matrix[3][3] = {{cos_a, -sin_a, 0}, {sin_a, cos_a, 0}, {0, 0, 1}};
    for (int i = 0; i < 3; i++) {
        result[i] = 0;
        for (int j = 0; j < 3; j++) {
            result[i] += rotation_matrix[i][j] * point[j];
        }
    }
    return result[0];
}

void translate_point(double point[3], double vector[3], double result[3]) {
    for (int i = 0; i < 3; i++) {
        result[i] = point[i] + vector[i];
    }
}

void transform_sequence(double points[3][3], double angles[3], double vector[3], double result[3][3]) {
    for (int i = 0; i < 3; i++) {
        double rotated_point[3];
        rotate_point(points[i], angles[i], rotated_point);
        translate_point(rotated_point, vector, result[i]);
    }
}

int main() {
    double points[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    double angles[3] = {PI / 4, PI / 3, PI / 2};
    double vector[3] = {1, 1, 1};
    double result[3][3];
    transform_sequence(points, angles, vector, result);
    for (int i = 0; i < 3; i++) {
        printf("[");
        for (int j = 0; j < 3; j++) {
            printf("%f", result[i][j]);
            if (j < 2) printf(", ");
        }
        printf("]\n");
    }
    return 0;
}