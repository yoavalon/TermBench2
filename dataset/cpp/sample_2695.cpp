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

    Vector3D scale(double factor) const {
        return Vector3D(x * factor, y * factor, z * factor);
    }

    double dot(const Vector3D& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    double magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vector3D normalize() const {
        double mag = magnitude();
        return Vector3D(x / mag, y / mag, z / mag);
    }
};

class Matrix3D {
public:
    double data[3][3];

    Matrix3D(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
        data[0][0] = a; data[0][1] = b; data[0][2] = c;
        data[1][0] = d; data[1][1] = e; data[1][2] = f;
        data[2][0] = g; data[2][1] = h; data[2][2] = i;
    }

    Matrix3D multiply(const Matrix3D& other) const {
        double result[3][3];
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result[i][j] = 0;
                for (int k = 0; k < 3; ++k) {
                    result[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return Matrix3D(result[0][0], result[0][1], result[0][2],
                         result[1][0], result[1][1], result[1][2],
                         result[2][0], result[2][1], result[2][2]);
    }

    Vector3D transform(const Vector3D& vector) const {
        double x = data[0][0] * vector.x + data[0][1] * vector.y + data[0][2] * vector.z;
        double y = data[1][0] * vector.x + data[1][1] * vector.y + data[1][2] * vector.z;
        double z = data[2][0] * vector.x + data[2][1] * vector.y + data[2][2] * vector.z;
        return Vector3D(x, y, z);
    }
};

Matrix3D rotation_matrix(const std::string& axis, double theta) {
    if (axis == "x") {
        return Matrix3D(1, 0, 0, 0, std::cos(theta), -std::sin(theta), 0, std::sin(theta), std::cos(theta));
    } else if (axis == "y") {
        return Matrix3D(std::cos(theta), 0, std::sin(theta), 0, 1, 0, -std::sin(theta), 0, std::cos(theta));
    } else if (axis == "z") {
        return Matrix3D(std::cos(theta), -std::sin(theta), 0, std::sin(theta), std::cos(theta), 0, 0, 0, 1);
    }
}

void main() {
    Vector3D v1(1, 2, 3);
    Vector3D v2(4, 5, 6);
    Vector3D v3 = v1.add(v2);
    Vector3D v4 = v2.subtract(v1);
    Vector3D v5 = v3.scale(2);
    double dot_product = v1.dot(v2);
    double magnitude_v1 = v1.magnitude();
    Vector3D normalized_v1 = v1.normalize();
    Matrix3D rot_x = rotation_matrix("x", M_PI / 4);
    Matrix3D rot_y = rotation_matrix("y", M_PI / 4);
    Matrix3D rot_z = rotation_matrix("z", M_PI / 4);
    Vector3D v6 = rot_x.transform(v1);
    Vector3D v7 = rot_y.transform(v1);
    Vector3D v8 = rot_z.transform(v1);
    Matrix3D matrix_product = rot_x.multiply(rot_y);
    std::cout << v3.x << " " << v3.y << " " << v3.z << std::endl;
    std::cout << v4.x << " " << v4.y << " " << v4.z << std::endl;
    std::cout << v5.x << " " << v5.y << " " << v5.z << std::endl;
    std::cout << dot_product << std::endl;
    std::cout << magnitude_v1 << std::endl;
    std::cout << normalized_v1.x << " " << normalized_v1.y << " " << normalized_v1.z << std::endl;
    std::cout << v6.x << " " << v6.y << " " << v6.z << std::endl;
    std::cout << v7.x << " " << v7.y << " " << v7.z << std::endl;
    std::cout << v8.x << " " << v8.y << " " << v8.z << std::endl;
    std::cout << matrix_product.data[0][0] << " " << matrix_product.data[0][1] << " " << matrix_product.data[0][2] << std::endl;
    std::cout << matrix_product.data[1][0] << " " << matrix_product.data[1][1] << " " << matrix_product.data[1][2] << std::endl;
    std::cout << matrix_product.data[2][0] << " " << matrix_product.data[2][1] << " " << matrix_product.data[2][2] << std::endl;
}

int main() {
    main();
    return 0;
}