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

void CoordinateTransformer_rotate_x(CoordinateTransformer *self, double angle) {
    double cos = cos(angle);
    double sin = sin(angle);
    double temp_b = self->b;
    double temp_c = self->c;
    self->b = cos * temp_b - sin * temp_c;
    self->c = sin * temp_b + cos * temp_c;
}

void CoordinateTransformer_rotate_y(CoordinateTransformer *self, double angle) {
    double cos = cos(angle);
    double sin = sin(angle);
    double temp_a = self->a;
    double temp_c = self->c;
    self->a = cos * temp_a + sin * temp_c;
    self->c = -sin * temp_a + cos * temp_c;
}

void CoordinateTransformer_rotate_z(CoordinateTransformer *self, double angle) {
    double cos = cos(angle);
    double sin = sin(angle);
    double temp_a = self->a;
    double temp_b = self->b;
    self->a = cos * temp_a - sin * temp_b;
    self->b = sin * temp_a + cos * temp_b;
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

void CoordinateTransformer_get_coordinates(CoordinateTransformer *self, double *x, double *y, double *z) {
    *x = self->a;
    *y = self->b;
    *z = self->c;
}

void transform_sequence() {
    CoordinateTransformer transformer;
    CoordinateTransformer_init(&transformer, 1, 0, 0);
    double angles[] = {M_PI / 4, M_PI / 3, M_PI / 6};
    double factors[] = {1.1, 0.9, 1.2};
    double translations[][3] = {{1, 2, 3}, {-1, -2, -3}, {0, 0, 0}};
    int angle_index = 0;
    int factor_index = 0;
    int translation_index = 0;
    while (1) {
        double angle = angles[angle_index];
        double factor = factors[factor_index];
        double dx = translations[translation_index][0];
        double dy = translations[translation_index][1];
        double dz = translations[translation_index][2];
        CoordinateTransformer_rotate_x(&transformer, angle);
        CoordinateTransformer_rotate_y(&transformer, angle);
        CoordinateTransformer_rotate_z(&transformer, angle);
        CoordinateTransformer_scale(&transformer, factor);
        CoordinateTransformer_translate(&transformer, dx, dy, dz);
        double x, y, z;
        CoordinateTransformer_get_coordinates(&transformer, &x, &y, &z);
        printf("Coordinates: (%.2f, %.2f, %.2f)\n", x, y, z);
        angle_index = (angle_index + 1) % 3;
        factor_index = (factor_index + 1) % 3;
        translation_index = (translation_index + 1) % 3;
    }
}

int main() {
    transform_sequence();
    return 0;
}