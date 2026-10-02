#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Transformation;

Transformation rotate(Transformation obj, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    double new_x = obj.x * cos_a - obj.y * sin_a;
    double new_y = obj.x * sin_a + obj.y * cos_a;
    obj.x = new_x;
    obj.y = new_y;
    return obj;
}

Transformation translate(Transformation obj, double dx, double dy, double dz) {
    obj.x += dx;
    obj.y += dy;
    obj.z += dz;
    return obj;
}

Transformation scale(Transformation obj, double sx, double sy, double sz) {
    obj.x *= sx;
    obj.y *= sy;
    obj.z *= sz;
    return obj;
}

Transformation transform_sequence(Transformation obj, double *rotations, int num_rotations, double (*translations)[3], int num_translations, double (*scales)[3], int num_scales) {
    for (int i = 0; i < num_rotations; i++) {
        obj = rotate(obj, rotations[i]);
    }
    for (int i = 0; i < num_translations; i++) {
        obj = translate(obj, translations[i][0], translations[i][1], translations[i][2]);
    }
    for (int i = 0; i < num_scales; i++) {
        obj = scale(obj, scales[i][0], scales[i][1], scales[i][2]);
    }
    return obj;
}

int main() {
    Transformation obj = {1.0, 2.0, 3.0};
    double rotations[] = {0.1, 0.2, 0.3};
    double translations[][3] = {{0.5, 0.5, 0.5}, {1.0, 1.0, 1.0}};
    double scales[][3] = {{1.5, 1.5, 1.5}, {2.0, 2.0, 2.0}};
    while (1) {
        Transformation transformed_obj = transform_sequence(obj, rotations, 3, translations, 2, scales, 2);
        printf("Transformed coordinates: (%f, %f, %f)\n", transformed_obj.x, transformed_obj.y, transformed_obj.z);
    }
    return 0;
}