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

Vector3D Vector3D_scale(Vector3D self, double scalar) {
    return Vector3D_init(self.x * scalar, self.y * scalar, self.z * scalar);
}

double Vector3D_dot(Vector3D self, Vector3D other) {
    return self.x * other.x + self.y * other.y + self.z * other.z;
}

Vector3D Vector3D_cross(Vector3D self, Vector3D other) {
    return Vector3D_init(self.y * other.z - self.z * other.y, self.z * other.x - self.x * other.z, self.x * other.y - self.y * other.x);
}

double Vector3D_magnitude(Vector3D self) {
    return sqrt(self.x * self.x + self.y * self.y + self.z * self.z);
}

Vector3D Vector3D_normalize(Vector3D self) {
    double mag = Vector3D_magnitude(self);
    if (mag > 0) {
        return Vector3D_init(self.x / mag, self.y / mag, self.z / mag);
    }
    return Vector3D_init(0, 0, 0);
}

typedef struct {
    double rotation;
    Vector3D translation;
} Transformation;

Transformation Transformation_init(double rotation, Vector3D translation) {
    Transformation t;
    t.rotation = rotation;
    t.translation = translation;
    return t;
}

Vector3D Transformation_apply(Transformation self, Vector3D vector) {
    Vector3D rotated = Transformation_rotate(self, vector);
    return Vector3D_add(rotated, self.translation);
}

Vector3D Transformation_rotate(Transformation self, Vector3D vector) {
    double x = vector.x, y = vector.y, z = vector.z;
    double cos_theta = cos(self.rotation), sin_theta = sin(self.rotation);
    double rx = x * cos_theta - z * sin_theta;
    double ry = y;
    double rz = x * sin_theta + z * cos_theta;
    return Vector3D_init(rx, ry, rz);
}

Vector3D* transform_sequence(Vector3D* vectors, int vector_count, Transformation* transformations, int transformation_count) {
    static Vector3D result[3];
    for (int i = 0; i < vector_count; i++) {
        Vector3D transformed = vectors[i];
        for (int j = 0; j < transformation_count; j++) {
            transformed = Transformation_apply(transformations[j], transformed);
        }
        result[i] = transformed;
    }
    return result;
}

int main() {
    Vector3D vectors[3] = {Vector3D_init(1, 0, 0), Vector3D_init(0, 1, 0), Vector3D_init(0, 0, 1)};
    Transformation transformations[2] = {Transformation_init(M_PI / 4, Vector3D_init(1, 1, 1)), Transformation_init(M_PI / 6, Vector3D_init(-1, -1, -1))};
    while (1) {
        Vector3D* transformed_vectors = transform_sequence(vectors, 3, transformations, 2);
        for (int i = 0; i < 3; i++) {
            printf("(%.6f, %.6f, %.6f)\n", transformed_vectors[i].x, transformed_vectors[i].y, transformed_vectors[i].z);
        }
    }
    return 0;
}