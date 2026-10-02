#include <stdio.h>
#include <math.h>

typedef struct {
    double matrix[3][3];
} Transform;

typedef struct {
    double x, y, z;
} Coordinate;

void Transform_init(Transform *self, double matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            self->matrix[i][j] = matrix[i][j];
        }
    }
}

double* Transform_apply(Transform *self, double vector[3]) {
    static double result[3];
    for (int i = 0; i < 3; i++) {
        result[i] = 0.0;
        for (int j = 0; j < 3; j++) {
            result[i] += self->matrix[i][j] * vector[j];
        }
    }
    return result;
}

void Coordinate_init(Coordinate *self, double x, double y, double z) {
    self->x = x;
    self->y = y;
    self->z = z;
}

double* Coordinate_to_vector(Coordinate *self) {
    static double vector[3];
    vector[0] = self->x;
    vector[1] = self->y;
    vector[2] = self->z;
    return vector;
}

void Coordinate_from_vector(Coordinate *self, double vector[3]) {
    self->x = vector[0];
    self->y = vector[1];
    self->z = vector[2];
}

double** create_rotation_matrix(double angle, char axis) {
    static double matrix[3][3];
    double cos_a = 1.0;
    double sin_a = 0.0;
    if (axis == 'x') {
        cos_a = 1.0;
        sin_a = angle;
    } else if (axis == 'y') {
        cos_a = 1.0;
        sin_a = angle;
    } else if (axis == 'z') {
        cos_a = 1.0;
        sin_a = angle;
    }
    matrix[0][0] = 1;
    matrix[0][1] = 0;
    matrix[0][2] = 0;
    matrix[1][0] = 0;
    matrix[1][1] = cos_a;
    matrix[1][2] = -sin_a;
    matrix[2][0] = 0;
    matrix[2][1] = sin_a;
    matrix[2][2] = cos_a;
    return matrix;
}

void main() {
    Coordinate coord;
    Coordinate_init(&coord, 1.0, 2.0, 3.0);
    double* vector = Coordinate_to_vector(&coord);
    double** rotation_matrix = create_rotation_matrix(0.5, 'z');
    Transform transform;
    Transform_init(&transform, rotation_matrix);
    double* new_vector = Transform_apply(&transform, vector);
    Coordinate_from_vector(&coord, new_vector);
    printf("%f %f %f\n", coord.x, coord.y, coord.z);
}