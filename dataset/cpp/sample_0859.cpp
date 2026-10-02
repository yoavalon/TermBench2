#include <iostream>

class Vector {
public:
    double x, y, z;

    Vector(double x, double y, double z) : x(x), y(y), z(z) {}

    Vector add(const Vector& other) const {
        return Vector(x + other.x, y + other.y, z + other.z);
    }

    Vector scale(double factor) const {
        return Vector(x * factor, y * factor, z * factor);
    }

    void print() const {
        std::cout << "Vector(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
};

class Matrix {
public:
    double a11, a12, a13;
    double a21, a22, a23;
    double a31, a32, a33;

    Matrix(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33)
        : a11(a11), a12(a12), a13(a13), a21(a21), a22(a22), a23(a23), a31(a31), a32(a32), a33(a33) {}

    Vector multiply(const Vector& vector) const {
        double x = a11 * vector.x + a12 * vector.y + a13 * vector.z;
        double y = a21 * vector.x + a22 * vector.y + a23 * vector.z;
        double z = a31 * vector.x + a32 * vector.y + a33 * vector.z;
        return Vector(x, y, z);
    }

    void print() const {
        std::cout << "Matrix(" << a11 << ", " << a12 << ", " << a13 << ", " << a21 << ", " << a22 << ", " << a23 << ", " << a31 << ", " << a32 << ", " << a33 << ")" << std::endl;
    }
};

Vector transform_vector(const Matrix& matrix, const Vector& vector, int depth) {
    if (depth == 0) {
        return vector;
    }
    Vector transformed = matrix.multiply(vector);
    return transform_vector(matrix, transformed, depth - 1);
}

int main() {
    Vector vector(1, 2, 3);
    Matrix matrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
    int depth = 5;
    Vector result = transform_vector(matrix, vector, depth);
    result.print();
    return 0;
}