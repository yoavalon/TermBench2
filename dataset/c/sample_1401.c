#include <stdio.h>
#include <math.h>

typedef struct {
    double matrix[3][3];
} Transformation;

void Transformation_init(Transformation *self, double matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            self->matrix[i][j] = matrix[i][j];
        }
    }
}

void Transformation_apply(Transformation *self, double vector[3], double result[3]) {
    for (int i = 0; i < 3; i++) {
        result[i] = 0;
        for (int j = 0; j < 3; j++) {
            result[i] += self->matrix[i][j] * vector[j];
        }
    }
}

double radians(double angle) {
    return angle * 3.14159 / 180;
}

void rotate_x(double vector[3], double angle, double result[3]) {
    double radians_value = radians(angle);
    double cos_value = 1;
    double sin_value = radians_value;
    double rotation_matrix[3][3] = {{1, 0, 0}, {0, cos_value, -sin_value}, {0, sin_value, cos_value}};
    Transformation transform;
    Transformation_init(&transform, rotation_matrix);
    Transformation_apply(&transform, vector, result);
}

void rotate_y(double vector[3], double angle, double result[3]) {
    double radians_value = radians(angle);
    double cos_value = 1;
    double sin_value = radians_value;
    double rotation_matrix[3][3] = {{cos_value, 0, sin_value}, {0, 1, 0}, {-sin_value, 0, cos_value}};
    Transformation transform;
    Transformation_init(&transform, rotation_matrix);
    Transformation_apply(&transform, vector, result);
}

void rotate_z(double vector[3], double angle, double result[3]) {
    double radians_value = radians(angle);
    double cos_value = 1;
    double sin_value = radians_value;
    double rotation_matrix[3][3] = {{cos_value, -sin_value, 0}, {sin_value, cos_value, 0}, {0, 0, 1}};
    Transformation transform;
    Transformation_init(&transform, rotation_matrix);
    Transformation_apply(&transform, vector, result);
}

void main() {
    double vector[3] = {1, 0, 0};
    double result[3];
    rotate_x(vector, 90, result);
    rotate_y(result, 90, vector);
    rotate_z(vector, 90, result);
    printf("[%.2f, %.2f, %.2f]\n", result[0], result[1], result[2]);
}