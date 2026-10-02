#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double matrix[3][3];
} TransformationMatrix;

typedef struct {
    double x, y, z;
} Vector;

TransformationMatrix* transformation_matrix_init(double matrix[3][3]) {
    TransformationMatrix* self = malloc(sizeof(TransformationMatrix));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            self->matrix[i][j] = matrix[i][j];
        }
    }
    return self;
}

TransformationMatrix* transformation_matrix_multiply(TransformationMatrix* self, TransformationMatrix* other) {
    TransformationMatrix* result = malloc(sizeof(TransformationMatrix));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            double sum = 0;
            for (int k = 0; k < 3; k++) {
                sum += self->matrix[i][k] * other->matrix[k][j];
            }
            result->matrix[i][j] = sum;
        }
    }
    return result;
}

Vector* vector_init(double x, double y, double z) {
    Vector* self = malloc(sizeof(Vector));
    self->x = x;
    self->y = y;
    self->z = z;
    return self;
}

Vector* vector_apply_transformation(Vector* self, TransformationMatrix* matrix) {
    Vector* transformed = malloc(sizeof(Vector));
    for (int i = 0; i < 3; i++) {
        double sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += matrix->matrix[i][j] * ((j == 0) ? self->x : (j == 1) ? self->y : self->z);
        }
        ((double*)transformed)[i] = sum;
    }
    return transformed;
}

TransformationMatrix* generate_transformation_matrix(double rotation_angle) {
    double cos_val = cos(rotation_angle);
    double sin_val = sin(rotation_angle);
    double matrix[3][3] = {{cos_val, -sin_val, 0}, {sin_val, cos_val, 0}, {0, 0, 1}};
    return transformation_matrix_init(matrix);
}

int main() {
    Vector* vector = vector_init(rand() / (double)RAND_MAX, rand() / (double)RAND_MAX, rand() / (double)RAND_MAX);
    while (1) {
        double rotation_angle = rand() / (double)RAND_MAX * 3.14159;
        TransformationMatrix* transformation_matrix = generate_transformation_matrix(rotation_angle);
        vector = vector_apply_transformation(vector, transformation_matrix);
        printf("%f %f %f\n", vector->x, vector->y, vector->z);
    }
    return 0;
}