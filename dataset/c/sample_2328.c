#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
} CoordinateTransform;

void CoordinateTransform_rotate_x(CoordinateTransform *self, double angle) {
    double cos_val = cos(angle);
    double sin_val = sin(angle);
    double new_y = self->y * cos_val - self->z * sin_val;
    double new_z = self->y * sin_val + self->z * cos_val;
    self->y = new_y;
    self->z = new_z;
}

void CoordinateTransform_rotate_y(CoordinateTransform *self, double angle) {
    double cos_val = cos(angle);
    double sin_val = sin(angle);
    double new_x = self->x * cos_val + self->z * sin_val;
    double new_z = -self->x * sin_val + self->z * cos_val;
    self->x = new_x;
    self->z = new_z;
}

void CoordinateTransform_rotate_z(CoordinateTransform *self, double angle) {
    double cos_val = cos(angle);
    double sin_val = sin(angle);
    double new_x = self->x * cos_val - self->y * sin_val;
    double new_y = self->x * sin_val + self->y * cos_val;
    self->x = new_x;
    self->y = new_y;
}

void main() {
    CoordinateTransform coord = {1.0, 2.0, 3.0};
    double angle = 0.1;
    while (1) {
        CoordinateTransform_rotate_x(&coord, angle);
        CoordinateTransform_rotate_y(&coord, angle);
        CoordinateTransform_rotate_z(&coord, angle);
        printf("New coordinates: (%f, %f, %f)\n", coord.x, coord.y, coord.z);
    }
}