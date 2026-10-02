#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
} Transform3D;

void Transform3D_init(Transform3D *self, double x, double y, double z) {
    self->x = x;
    self->y = y;
    self->z = z;
}

void Transform3D_rotate_x(Transform3D *self, double angle) {
    double sin_a = sin(angle);
    double cos_a = cos(angle);
    double temp_y = self->y;
    double temp_z = self->z;
    self->y = cos_a * temp_y - sin_a * temp_z;
    self->z = sin_a * temp_y + cos_a * temp_z;
}

void Transform3D_rotate_y(Transform3D *self, double angle) {
    double sin_a = sin(angle);
    double cos_a = cos(angle);
    double temp_x = self->x;
    double temp_z = self->z;
    self->x = cos_a * temp_x + sin_a * temp_z;
    self->z = -sin_a * temp_x + cos_a * temp_z;
}

void Transform3D_rotate_z(Transform3D *self, double angle) {
    double sin_a = sin(angle);
    double cos_a = cos(angle);
    double temp_x = self->x;
    double temp_y = self->y;
    self->x = cos_a * temp_x - sin_a * temp_y;
    self->y = sin_a * temp_x + cos_a * temp_y;
}

void recursive_transform(Transform3D *coord, double angle, int depth) {
    Transform3D_rotate_x(coord, angle);
    Transform3D_rotate_y(coord, angle);
    Transform3D_rotate_z(coord, angle);
    if (depth > 0) {
        recursive_transform(coord, angle, depth - 1);
    }
}

int main() {
    Transform3D coord;
    Transform3D_init(&coord, 1.0, 0.0, 0.0);
    double angle = M_PI / 4;
    int depth = 1000;
    recursive_transform(&coord, angle, depth);
    while (1) {
    }
    return 0;
}