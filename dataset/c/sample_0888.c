#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
    double z;
} Vector3D;

Vector3D Vector3D_init(double x, double y, double z) {
    Vector3D v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

Vector3D Vector3D_add(Vector3D a, Vector3D b) {
    return Vector3D_init(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector3D Vector3D_scale(Vector3D v, double scalar) {
    return Vector3D_init(v.x * scalar, v.y * scalar, v.z * scalar);
}

void Vector3D_repr(Vector3D v) {
    printf("Vector3D(%.1f, %.1f, %.1f)\n", v.x, v.y, v.z);
}

typedef struct {
    double matrix[3][3];
} Transformation;

Transformation Transformation_init(double matrix[3][3]) {
    Transformation t;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            t.matrix[i][j] = matrix[i][j];
        }
    }
    return t;
}

Vector3D Transformation_apply(Transformation t, Vector3D v) {
    double x = t.matrix[0][0] * v.x + t.matrix[0][1] * v.y + t.matrix[0][2] * v.z;
    double y = t.matrix[1][0] * v.x + t.matrix[1][1] * v.y + t.matrix[1][2] * v.z;
    double z = t.matrix[2][0] * v.x + t.matrix[2][1] * v.y + t.matrix[2][2] * v.z;
    return Vector3D_init(x, y, z);
}

Vector3D transform_sequence(Vector3D vector, Transformation *transformations, int index, int len) {
    if (index >= len) {
        return vector;
    }
    Transformation current_transformation = transformations[index];
    Vector3D transformed_vector = Transformation_apply(current_transformation, vector);
    return transform_sequence(transformed_vector, transformations, index + 1, len);
}

int main() {
    Vector3D vector = Vector3D_init(1, 2, 3);
    double matrix1[3][3] = {{1, 0, 0}, {0, 2, 0}, {0, 0, 3}};
    double matrix2[3][3] = {{0, 0, 1}, {1, 0, 0}, {0, 1, 0}};
    Transformation transformation1 = Transformation_init(matrix1);
    Transformation transformation2 = Transformation_init(matrix2);
    Transformation transformations[2] = {transformation1, transformation2};
    Vector3D final_vector = transform_sequence(vector, transformations, 0, 2);
    Vector3D_repr(final_vector);
    return 0;
}