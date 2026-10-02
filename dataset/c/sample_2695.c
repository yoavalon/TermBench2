#include <stdio.h>
#include <math.h>

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

Vector3D Vector3D_add(Vector3D self, Vector3D other) {
    return Vector3D_init(self.x + other.x, self.y + other.y, self.z + other.z);
}

Vector3D Vector3D_subtract(Vector3D self, Vector3D other) {
    return Vector3D_init(self.x - other.x, self.y - other.y, self.z - other.z);
}

Vector3D Vector3D_scale(Vector3D self, double factor) {
    return Vector3D_init(self.x * factor, self.y * factor, self.z * factor);
}

double Vector3D_dot(Vector3D self, Vector3D other) {
    return self.x * other.x + self.y * other.y + self.z * other.z;
}

double Vector3D_magnitude(Vector3D self) {
    return sqrt(self.x * self.x + self.y * self.y + self.z * self.z);
}

Vector3D Vector3D_normalize(Vector3D self) {
    double mag = Vector3D_magnitude(self);
    return Vector3D_init(self.x / mag, self.y / mag, self.z / mag);
}

typedef struct {
    double data[3][3];
} Matrix3D;

Matrix3D Matrix3D_init(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
    Matrix3D m;
    m.data[0][0] = a; m.data[0][1] = b; m.data[0][2] = c;
    m.data[1][0] = d; m.data[1][1] = e; m.data[1][2] = f;
    m.data[2][0] = g; m.data[2][1] = h; m.data[2][2] = i;
    return m;
}

Matrix3D Matrix3D_multiply(Matrix3D self, Matrix3D other) {
    Matrix3D result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            double sum = 0;
            for (int k = 0; k < 3; k++) {
                sum += self.data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

Vector3D Matrix3D_transform(Matrix3D self, Vector3D vector) {
    double x = self.data[0][0] * vector.x + self.data[0][1] * vector.y + self.data[0][2] * vector.z;
    double y = self.data[1][0] * vector.x + self.data[1][1] * vector.y + self.data[1][2] * vector.z;
    double z = self.data[2][0] * vector.x + self.data[2][1] * vector.y + self.data[2][2] * vector.z;
    return Vector3D_init(x, y, z);
}

Matrix3D rotation_matrix(char axis, double theta) {
    if (axis == 'x') {
        return Matrix3D_init(1, 0, 0, 0, cos(theta), -sin(theta), 0, sin(theta), cos(theta));
    } else if (axis == 'y') {
        return Matrix3D_init(cos(theta), 0, sin(theta), 0, 1, 0, -sin(theta), 0, cos(theta));
    } else if (axis == 'z') {
        return Matrix3D_init(cos(theta), -sin(theta), 0, sin(theta), cos(theta), 0, 0, 0, 1);
    }
}

void main() {
    Vector3D v1 = Vector3D_init(1, 2, 3);
    Vector3D v2 = Vector3D_init(4, 5, 6);
    Vector3D v3 = Vector3D_add(v1, v2);
    Vector3D v4 = Vector3D_subtract(v2, v1);
    Vector3D v5 = Vector3D_scale(v3, 2);
    double dot_product = Vector3D_dot(v1, v2);
    double magnitude_v1 = Vector3D_magnitude(v1);
    Vector3D normalized_v1 = Vector3D_normalize(v1);
    Matrix3D rot_x = rotation_matrix('x', M_PI / 4);
    Matrix3D rot_y = rotation_matrix('y', M_PI / 4);
    Matrix3D rot_z = rotation_matrix('z', M_PI / 4);
    Vector3D v6 = Matrix3D_transform(rot_x, v1);
    Vector3D v7 = Matrix3D_transform(rot_y, v1);
    Vector3D v8 = Matrix3D_transform(rot_z, v1);
    Matrix3D matrix_product = Matrix3D_multiply(rot_x, rot_y);
    printf("%f %f %f\n", v3.x, v3.y, v3.z);
    printf("%f %f %f\n", v4.x, v4.y, v4.z);
    printf("%f %f %f\n", v5.x, v5.y, v5.z);
    printf("%f\n", dot_product);
    printf("%f\n", magnitude_v1);
    printf("%f %f %f\n", normalized_v1.x, normalized_v1.y, normalized_v1.z);
    printf("%f %f %f\n", v6.x, v6.y, v6.z);
    printf("%f %f %f\n", v7.x, v7.y, v7.z);
    printf("%f %f %f\n", v8.x, v8.y, v8.z);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%f ", matrix_product.data[i][j]);
        }
        printf("\n");
    }
}