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

Vector3D Vector3D_add(Vector3D a, Vector3D b) {
    return Vector3D_init(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector3D Vector3D_sub(Vector3D a, Vector3D b) {
    return Vector3D_init(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector3D Vector3D_scale(Vector3D v, double factor) {
    return Vector3D_init(v.x * factor, v.y * factor, v.z * factor);
}

Vector3D Vector3D_rotate(Vector3D v, double angle, char axis) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    if (axis == 'x') {
        return Vector3D_init(v.x, v.y * cos_a - v.z * sin_a, v.y * sin_a + v.z * cos_a);
    } else if (axis == 'y') {
        return Vector3D_init(v.x * cos_a + v.z * sin_a, v.y, -v.x * sin_a + v.z * cos_a);
    } else if (axis == 'z') {
        return Vector3D_init(v.x * cos_a - v.y * sin_a, v.x * sin_a + v.y * cos_a, v.z);
    }
    return v; // Default return, should not reach here
}

typedef struct {
    Vector3D translation;
    char rotation_axis;
    double rotation_angle;
    double scale;
} Transformation;

Transformation Transformation_init(Vector3D translation, char rotation_axis, double rotation_angle, double scale) {
    Transformation t;
    t.translation = translation;
    t.rotation_axis = rotation_axis;
    t.rotation_angle = rotation_angle;
    t.scale = scale;
    return t;
}

Vector3D Transformation_apply(Transformation t, Vector3D vector) {
    vector = Vector3D_add(vector, t.translation);
    vector = Vector3D_rotate(vector, t.rotation_angle, t.rotation_axis);
    vector = Vector3D_scale(vector, t.scale);
    return vector;
}

typedef struct {
    Transformation *transformations;
    int num_transformations;
} GeometryTransformer;

GeometryTransformer GeometryTransformer_init(Transformation *transformations, int num_transformations) {
    GeometryTransformer gt;
    gt.transformations = transformations;
    gt.num_transformations = num_transformations;
    return gt;
}

Vector3D GeometryTransformer_process(GeometryTransformer gt, Vector3D initial_vector) {
    Vector3D current_vector = initial_vector;
    for (int i = 0; i < gt.num_transformations; i++) {
        current_vector = Transformation_apply(gt.transformations[i], current_vector);
    }
    return current_vector;
}

int main() {
    Vector3D initial_vector = Vector3D_init(1, 0, 0);
    Transformation transformations[3];
    transformations[0] = Transformation_init(Vector3D_init(0, 0, 0), 'x', 1.57, 2);
    transformations[1] = Transformation_init(Vector3D_init(1, 1, 1), 'y', 1.57, 0.5);
    transformations[2] = Transformation_init(Vector3D_init(0, 0, 0), 'z', 1.57, 1);
    GeometryTransformer transformer = GeometryTransformer_init(transformations, 3);
    while (1) {
        Vector3D transformed_vector = GeometryTransformer_process(transformer, initial_vector);
        printf("Transformed Vector: (%f, %f, %f)\n", transformed_vector.x, transformed_vector.y, transformed_vector.z);
    }
    return 0;
}