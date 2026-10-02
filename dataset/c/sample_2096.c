#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Vector3D;

Vector3D Vector3D_init(double x, double y, double z) {
    Vector3D v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

Vector3D Vector3D_add(Vector3D self, Vector3D other) {
    return Vector3D_init(self.x + other.x, self.y + other.y, self.z + other.z);
}

Vector3D Vector3D_subtract(Vector3D self, Vector3D other) {
    return Vector3D_init(self.x - other.x, self.y - other.y, self.z - other.z);
}

Vector3D Vector3D_scale(Vector3D self, double scalar) {
    return Vector3D_init(self.x * scalar, self.y * scalar, self.z * scalar);
}

Vector3D Vector3D_normalize(Vector3D self) {
    double magnitude = sqrt(self.x * self.x + self.y * self.y + self.z * self.z);
    return Vector3D_init(self.x / magnitude, self.y / magnitude, self.z / magnitude);
}

typedef struct {
    double data[3][3];
} Matrix3x3;

Matrix3x3 Matrix3x3_init(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33) {
    Matrix3x3 m;
    m.data[0][0] = a11; m.data[0][1] = a12; m.data[0][2] = a13;
    m.data[1][0] = a21; m.data[1][1] = a22; m.data[1][2] = a23;
    m.data[2][0] = a31; m.data[2][1] = a32; m.data[2][2] = a33;
    return m;
}

Vector3D Matrix3x3_multiply_vector(Matrix3x3 self, Vector3D vector) {
    double x = self.data[0][0] * vector.x + self.data[0][1] * vector.y + self.data[0][2] * vector.z;
    double y = self.data[1][0] * vector.x + self.data[1][1] * vector.y + self.data[1][2] * vector.z;
    double z = self.data[2][0] * vector.x + self.data[2][1] * vector.y + self.data[2][2] * vector.z;
    return Vector3D_init(x, y, z);
}

typedef struct {
    Matrix3x3 matrix;
} Transformation;

Transformation Transformation_init(Matrix3x3 matrix) {
    Transformation t;
    t.matrix = matrix;
    return t;
}

Vector3D Transformation_transform(Transformation self, Vector3D vector) {
    return Matrix3x3_multiply_vector(self.matrix, vector);
}

void main() {
    Vector3D vector = Vector3D_init(1.0, 2.0, 3.0);
    Matrix3x3 matrix = Matrix3x3_init(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    Transformation transformation = Transformation_init(matrix);
    Vector3D transformed_vector = Transformation_transform(transformation, vector);
    printf("Original Vector: (%f, %f, %f)\n", vector.x, vector.y, vector.z);
    printf("Transformed Vector: (%f, %f, %f)\n", transformed_vector.x, transformed_vector.y, transformed_vector.z);
}