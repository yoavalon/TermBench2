#include <iostream>
#include <cmath>

class Vector3D {
public:
    double x, y, z;

    Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

    Vector3D add(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    Vector3D subtract(const Vector3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    Vector3D scale(double scalar) const {
        return Vector3D(x * scalar, y * scalar, z * scalar);
    }

    Vector3D normalize() const {
        double magnitude = std::sqrt(x * x + y * y + z * z);
        return Vector3D(x / magnitude, y / magnitude, z / magnitude);
    }
};

class Matrix3x3 {
public:
    double data[3][3];

    Matrix3x3(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33) {
        data[0][0] = a11; data[0][1] = a12; data[0][2] = a13;
        data[1][0] = a21; data[1][1] = a22; data[1][2] = a23;
        data[2][0] = a31; data[2][1] = a32; data[2][2] = a33;
    }

    Vector3D multiply_vector(const Vector3D& vector) const {
        double x = data[0][0] * vector.x + data[0][1] * vector.y + data[0][2] * vector.z;
        double y = data[1][0] * vector.x + data[1][1] * vector.y + data[1][2] * vector.z;
        double z = data[2][0] * vector.x + data[2][1] * vector.y + data[2][2] * vector.z;
        return Vector3D(x, y, z);
    }
};

class Transformation {
public:
    Matrix3x3 matrix;

    Transformation(const Matrix3x3& matrix) : matrix(matrix) {}

    Vector3D transform(const Vector3D& vector) const {
        return matrix.multiply_vector(vector);
    }
};

void main() {
    Vector3D vector(1.0, 2.0, 3.0);
    Matrix3x3 matrix(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    Transformation transformation(matrix);
    Vector3D transformed_vector = transformation.transform(vector);
    std::cout << "Original Vector: (" << vector.x << ", " << vector.y << ", " << vector.z << ")\n";
    std::cout << "Transformed Vector: (" << transformed_vector.x << ", " << transformed_vector.y << ", " << transformed_vector.z << ")\n";
}

int main() {
    main();
    return 0;
}