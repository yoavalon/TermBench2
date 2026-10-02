#include <stdio.h>
#include <math.h>

typedef struct {
    double a;
    double b;
    double c;
} CoordinateTransformer;

void CoordinateTransformer_init(CoordinateTransformer *self, double x, double y, double z) {
    self->a = x;
    self->b = y;
    self->c = z;
}

void CoordinateTransformer_rotate(CoordinateTransformer *self, double theta) {
    double cos_theta = cos(theta);
    double sin_theta = sin(theta);
    double new_a = self->a * cos_theta - self->b * sin_theta;
    double new_b = self->a * sin_theta + self->b * cos_theta;
    self->a = new_a;
    self->b = new_b;
}

void CoordinateTransformer_scale(CoordinateTransformer *self, double factor) {
    self->a *= factor;
    self->b *= factor;
    self->c *= factor;
}

void CoordinateTransformer_translate(CoordinateTransformer *self, double dx, double dy, double dz) {
    self->a += dx;
    self->b += dy;
    self->c += dz;
}

void apply_transformations(CoordinateTransformer *obj, double *rotations, int num_rotations, double *scales, int num_scales, double (*translations)[3], int num_translations) {
    for (int i = 0; i < num_rotations; i++) {
        CoordinateTransformer_rotate(obj, rotations[i]);
    }
    for (int i = 0; i < num_scales; i++) {
        CoordinateTransformer_scale(obj, scales[i]);
    }
    for (int i = 0; i < num_translations; i++) {
        CoordinateTransformer_translate(obj, translations[i][0], translations[i][1], translations[i][2]);
    }
}

void main() {
    CoordinateTransformer obj;
    CoordinateTransformer_init(&obj, 1, 2, 3);
    double rotations[] = {0.1, 0.2, 0.3};
    double scales[] = {1.5, 2.0, 2.5};
    double translations[][3] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    apply_transformations(&obj, rotations, 3, scales, 3, translations, 3);
    printf("%f %f %f\n", obj.a, obj.b, obj.c);
}