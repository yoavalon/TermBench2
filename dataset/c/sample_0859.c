#include <stdio.h>

typedef struct Vector {
    double x, y, z;
} Vector;

typedef struct Matrix {
    double a11, a12, a13;
    double a21, a22, a23;
    double a31, a32, a33;
} Matrix;

Vector Vector_init(double x, double y, double z) {
    Vector v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

Vector Vector_add(Vector v1, Vector v2) {
    Vector v;
    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
    v.z = v1.z + v2.z;
    return v;
}

Vector Vector_scale(Vector v, double factor) {
    Vector v_scaled;
    v_scaled.x = v.x * factor;
    v_scaled.y = v.y * factor;
    v_scaled.z = v.z * factor;
    return v_scaled;
}

void Vector_repr(Vector v) {
    printf("Vector(%.1f, %.1f, %.1f)\n", v.x, v.y, v.z);
}

Matrix Matrix_init(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33) {
    Matrix m;
    m.a11 = a11;
    m.a12 = a12;
    m.a13 = a13;
    m.a21 = a21;
    m.a22 = a22;
    m.a23 = a23;
    m.a31 = a31;
    m.a32 = a32;
    m.a33 = a33;
    return m;
}

Vector Matrix_multiply(Matrix m, Vector v) {
    Vector result;
    result.x = m.a11 * v.x + m.a12 * v.y + m.a13 * v.z;
    result.y = m.a21 * v.x + m.a22 * v.y + m.a23 * v.z;
    result.z = m.a31 * v.x + m.a32 * v.y + m.a33 * v.z;
    return result;
}

void Matrix_repr(Matrix m) {
    printf("Matrix(%.1f, %.1f, %.1f, %.1f, %.1f, %.1f, %.1f, %.1f, %.1f)\n", m.a11, m.a12, m.a13, m.a21, m.a22, m.a23, m.a31, m.a32, m.a33);
}

Vector transform_vector(Matrix matrix, Vector vector, int depth) {
    if (depth == 0) {
        return vector;
    }
    Vector transformed = Matrix_multiply(matrix, vector);
    return transform_vector(matrix, transformed, depth - 1);
}

void main() {
    Vector vector = Vector_init(1, 2, 3);
    Matrix matrix = Matrix_init(1, 0, 0, 0, 1, 0, 0, 0, 1);
    int depth = 5;
    Vector result = transform_vector(matrix, vector, depth);
    Vector_repr(result);
}