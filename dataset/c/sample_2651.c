#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
} Vector3D;

Vector3D Vector3D_init(double x, double y, double z) {
    Vector3D vec;
    vec.x = x;
    vec.y = y;
    vec.z = z;
    return vec;
}

Vector3D Vector3D_add(Vector3D a, Vector3D b) {
    return Vector3D_init(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector3D Vector3D_subtract(Vector3D a, Vector3D b) {
    return Vector3D_init(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector3D Vector3D_scale(Vector3D a, double scalar) {
    return Vector3D_init(a.x * scalar, a.y * scalar, a.z * scalar);
}

double Vector3D_magnitude(Vector3D a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

typedef struct {
    double rotation_matrix[3][3];
    Vector3D translation_vector;
} Transformation;

Transformation Transformation_init(double rotation_matrix[3][3], Vector3D translation_vector) {
    Transformation trans;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            trans.rotation_matrix[i][j] = rotation_matrix[i][j];
        }
    }
    trans.translation_vector = translation_vector;
    return trans;
}

Vector3D Transformation_apply(Transformation trans, Vector3D vector) {
    double x = vector.x * trans.rotation_matrix[0][0] + vector.y * trans.rotation_matrix[0][1] + vector.z * trans.rotation_matrix[0][2];
    double y = vector.x * trans.rotation_matrix[1][0] + vector.y * trans.rotation_matrix[1][1] + vector.z * trans.rotation_matrix[1][2];
    double z = vector.x * trans.rotation_matrix[2][0] + vector.y * trans.rotation_matrix[2][1] + vector.z * trans.rotation_matrix[2][2];
    Vector3D translated_vector = Vector3D_add(Vector3D_init(x, y, z), trans.translation_vector);
    return translated_vector;
}

Vector3D* generate_sequence(Vector3D start, Transformation transformation, int steps) {
    Vector3D* sequence = (Vector3D*)malloc(steps * sizeof(Vector3D));
    Vector3D current_vector = start;
    for (int i = 0; i < steps; i++) {
        sequence[i] = current_vector;
        current_vector = Transformation_apply(transformation, current_vector);
    }
    return sequence;
}

void main() {
    Vector3D start_vector = Vector3D_init(1, 0, 0);
    double rotation_matrix[3][3] = {{0, -1, 0}, {1, 0, 0}, {0, 0, 1}};
    Vector3D translation_vector = Vector3D_init(1, 1, 1);
    Transformation transformation = Transformation_init(rotation_matrix, translation_vector);
    Vector3D* sequence = generate_sequence(start_vector, transformation, 10);
    for (int i = 0; i < 10; i++) {
        printf("(%.1f, %.1f, %.1f)\n", sequence[i].x, sequence[i].y, sequence[i].z);
    }
    free(sequence);
}