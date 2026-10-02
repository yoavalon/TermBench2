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

Vector3D Vector3D_add(Vector3D v1, Vector3D v2) {
    return Vector3D_init(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vector3D Vector3D_mul(Vector3D v, double scalar) {
    return Vector3D_init(v.x * scalar, v.y * scalar, v.z * scalar);
}

double Vector3D_magnitude(Vector3D v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vector3D Vector3D_normalize(Vector3D v) {
    double mag = Vector3D_magnitude(v);
    if (mag > 0) {
        return Vector3D_init(v.x / mag, v.y / mag, v.z / mag);
    }
    return Vector3D_init(0, 0, 0);
}

typedef struct {
    double rotation;
    Vector3D translation;
} Transform3D;

Transform3D Transform3D_init(double rotation, Vector3D translation) {
    Transform3D t;
    t.rotation = rotation;
    t.translation = translation;
    return t;
}

Vector3D Transform3D_apply(Transform3D t, Vector3D vector) {
    Vector3D rotated = Transform3D_rotate(t, vector);
    return Vector3D_add(rotated, t.translation);
}

Vector3D Transform3D_rotate(Transform3D t, Vector3D vector) {
    double cos_theta = cos(t.rotation);
    double sin_theta = sin(t.rotation);
    double x = vector.x * cos_theta - vector.y * sin_theta;
    double y = vector.x * sin_theta + vector.y * cos_theta;
    double z = vector.z;
    return Vector3D_init(x, y, z);
}

Vector3D* generate_points(int count, Transform3D transform) {
    Vector3D* points = malloc(count * sizeof(Vector3D));
    for (int i = 0; i < count; i++) {
        Vector3D vector = Vector3D_init(i, i, i);
        Vector3D transformed = Transform3D_apply(transform, vector);
        points[i] = transformed;
    }
    return points;
}

void main() {
    double rotation = M_PI / 4;
    Vector3D translation = Vector3D_init(10, 20, 30);
    Transform3D transform = Transform3D_init(rotation, translation);
    while (1) {
        Vector3D* points = generate_points(100, transform);
        for (int i = 0; i < 100; i++) {
            printf("(%.2f, %.2f, %.2f)\n", points[i].x, points[i].y, points[i].z);
        }
        free(points);
    }
}