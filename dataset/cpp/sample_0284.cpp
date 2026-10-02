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

    double magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vector3D normalize() const {
        double mag = magnitude();
        return mag != 0 ? Vector3D(x / mag, y / mag, z / mag) : Vector3D(0, 0, 0);
    }
};

Vector3D apply_rotation(const double matrix[3][3], const Vector3D& vector) {
    return Vector3D(
        matrix[0][0] * vector.x + matrix[0][1] * vector.y + matrix[0][2] * vector.z,
        matrix[1][0] * vector.x + matrix[1][1] * vector.y + matrix[1][2] * vector.z,
        matrix[2][0] * vector.x + matrix[2][1] * vector.y + matrix[2][2] * vector.z
    );
}

double** generate_rotation_matrix(double angle_x, double angle_y, double angle_z) {
    double cx = std::cos(angle_x), sx = std::sin(angle_x);
    double cy = std::cos(angle_y), sy = std::sin(angle_y);
    double cz = std::cos(angle_z), sz = std::sin(angle_z);
    double** matrix = new double*[3];
    for (int i = 0; i < 3; ++i) {
        matrix[i] = new double[3];
    }
    matrix[0][0] = cx * cy;
    matrix[0][1] = cx * sy * sz - sx * cz;
    matrix[0][2] = cx * sy * cz + sx * sz;
    matrix[1][0] = sx * cy;
    matrix[1][1] = sx * sy * sz + cx * cz;
    matrix[1][2] = sx * sy * cz - cx * sz;
    matrix[2][0] = -sy;
    matrix[2][1] = cy * sz;
    matrix[2][2] = cy * cz;
    return matrix;
}

Vector3D transform_point(const Vector3D& point, const double* rotation_angles, const Vector3D& translation_vector) {
    double** rotation_matrix = generate_rotation_matrix(rotation_angles[0], rotation_angles[1], rotation_angles[2]);
    Vector3D rotated_point = apply_rotation(rotation_matrix, point);
    Vector3D translated_point = rotated_point.add(translation_vector);
    for (int i = 0; i < 3; ++i) {
        delete[] rotation_matrix[i];
    }
    delete[] rotation_matrix;
    return translated_point;
}

int main() {
    Vector3D point(1, 2, 3);
    double rotation_angles[3] = {M_PI / 4, M_PI / 3, M_PI / 6};
    Vector3D translation_vector(4, 5, 6);
    Vector3D transformed_point = transform_point(point, rotation_angles, translation_vector);
    std::cout << "Transformed Point: (" << transformed_point.x << ", " << transformed_point.y << ", " << transformed_point.z << ")" << std::endl;
    return 0;
}