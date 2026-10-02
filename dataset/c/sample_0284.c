#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
} Vector3D;

Vector3D create_vector3D(double x, double y, double z) {
    Vector3D v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

Vector3D add(Vector3D v1, Vector3D v2) {
    return create_vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector3D subtract(Vector3D v1, Vector3D v2) {
    return create_vector3D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vector3D scale(Vector3D v, double factor) {
    return create_vector3D(v.x * factor, v.y * factor, v.z * factor);
}

double magnitude(Vector3D v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vector3D normalize(Vector3D v) {
    double mag = magnitude(v);
    if (mag != 0) {
        return create_vector3D(v.x / mag, v.y / mag, v.z / mag);
    } else {
        return create_vector3D(0, 0, 0);
    }
}

Vector3D apply_rotation(double matrix[3][3], Vector3D vector) {
    return create_vector3D(matrix[0][0] * vector.x + matrix[0][1] * vector.y + matrix[0][2] * vector.z,
                           matrix[1][0] * vector.x + matrix[1][1] * vector.y + matrix[1][2] * vector.z,
                           matrix[2][0] * vector.x + matrix[2][1] * vector.y + matrix[2][2] * vector.z);
}

void generate_rotation_matrix(double angle_x, double angle_y, double angle_z, double matrix[3][3]) {
    double cx = cos(angle_x), sx = sin(angle_x);
    double cy = cos(angle_y), sy = sin(angle_y);
    double cz = cos(angle_z), sz = sin(angle_z);
    matrix[0][0] = cx * cy;
    matrix[0][1] = cx * sy * sz - sx * cz;
    matrix[0][2] = cx * sy * cz + sx * sz;
    matrix[1][0] = sx * cy;
    matrix[1][1] = sx * sy * sz + cx * cz;
    matrix[1][2] = sx * sy * cz - cx * sz;
    matrix[2][0] = -sy;
    matrix[2][1] = cy * sz;
    matrix[2][2] = cy * cz;
}

Vector3D transform_point(Vector3D point, double rotation_angles[3], Vector3D translation_vector) {
    double rotation_matrix[3][3];
    generate_rotation_matrix(rotation_angles[0], rotation_angles[1], rotation_angles[2], rotation_matrix);
    Vector3D rotated_point = apply_rotation(rotation_matrix, point);
    Vector3D translated_point = add(rotated_point, translation_vector);
    return translated_point;
}

void main() {
    Vector3D point = create_vector3D(1, 2, 3);
    double rotation_angles[3] = {M_PI / 4, M_PI / 3, M_PI / 6};
    Vector3D translation_vector = create_vector3D(4, 5, 6);
    Vector3D transformed_point = transform_point(point, rotation_angles, translation_vector);
    printf("Transformed Point: (%f, %f, %f)\n", transformed_point.x, transformed_point.y, transformed_point.z);
}