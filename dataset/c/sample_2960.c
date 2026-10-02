#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
} CoordinateTransformer;

void CoordinateTransformer_init(CoordinateTransformer *self, double x, double y, double z) {
    self->x = x;
    self->y = y;
    self->z = z;
}

void CoordinateTransformer_rotate_x(CoordinateTransformer *self, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    double new_y = self->y * cos_a - self->z * sin_a;
    double new_z = self->y * sin_a + self->z * cos_a;
    self->y = new_y;
    self->z = new_z;
}

void CoordinateTransformer_rotate_y(CoordinateTransformer *self, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    double new_x = self->x * cos_a + self->z * sin_a;
    double new_z = -self->x * sin_a + self->z * cos_a;
    self->x = new_x;
    self->z = new_z;
}

void CoordinateTransformer_rotate_z(CoordinateTransformer *self, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    double new_x = self->x * cos_a - self->y * sin_a;
    double new_y = self->x * sin_a + self->y * cos_a;
    self->x = new_x;
    self->y = new_y;
}

void CoordinateTransformer_scale(CoordinateTransformer *self, double factor) {
    self->x *= factor;
    self->y *= factor;
    self->z *= factor;
}

void* generate_angles() {
    static double angle = 0;
    while (1) {
        double* angle_ptr = (double*)malloc(sizeof(double));
        *angle_ptr = angle;
        angle += M_PI / 180;
        return angle_ptr;
    }
}

void transform_sequence(CoordinateTransformer *transformer, void* (*angles)()) {
    while (1) {
        double* angle_ptr = (double*)angles();
        CoordinateTransformer_rotate_x(transformer, *angle_ptr);
        CoordinateTransformer_rotate_y(transformer, *angle_ptr);
        CoordinateTransformer_rotate_z(transformer, *angle_ptr);
        CoordinateTransformer_scale(transformer, 1.01);
        free(angle_ptr);
    }
}

int main() {
    CoordinateTransformer transformer;
    CoordinateTransformer_init(&transformer, 1, 0, 0);
    transform_sequence(&transformer, generate_angles);
    return 0;
}