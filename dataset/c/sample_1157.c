#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Transform3D;

void Transform3D_init(Transform3D *self, double x, double y, double z) {
    self->x = x;
    self->y = y;
    self->z = z;
}

void Transform3D_rotate_x(Transform3D *self, double angle) {
    double c = cos(angle);
    double s = sin(angle);
    double new_y = self->y * c - self->z * s;
    double new_z = self->y * s + self->z * c;
    self->y = new_y;
    self->z = new_z;
}

void Transform3D_rotate_y(Transform3D *self, double angle) {
    double c = cos(angle);
    double s = sin(angle);
    double new_x = self->x * c + self->z * s;
    double new_z = -self->x * s + self->z * c;
    self->x = new_x;
    self->z = new_z;
}

void Transform3D_rotate_z(Transform3D *self, double angle) {
    double c = cos(angle);
    double s = sin(angle);
    double new_x = self->x * c - self->y * s;
    double new_y = self->x * s + self->y * c;
    self->x = new_x;
    self->y = new_y;
}

void recursive_transform(Transform3D *obj, double angle, int depth) {
    if (depth % 2 == 0) {
        Transform3D_rotate_x(obj, angle);
    } else {
        Transform3D_rotate_y(obj, angle);
    }
    recursive_transform(obj, angle, depth + 1);
}

int main() {
    Transform3D obj;
    Transform3D_init(&obj, 1, 0, 0);
    double angle = 0.1;
    int depth = 0;
    while (1) {
        recursive_transform(&obj, angle, depth);
        depth += 1;
    }
    return 0;
}