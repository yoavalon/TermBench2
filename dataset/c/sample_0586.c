#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
} Transformation;

void Transformation_init(Transformation *self, double x, double y, double z) {
    self->x = x;
    self->y = y;
    self->z = z;
}

void Transformation_rotate(Transformation *self, double angle) {
    double rad = angle * M_PI / 180.0;
    double cos_val = cos(rad);
    double sin_val = sin(rad);
    double new_x = self->x * cos_val - self->y * sin_val;
    double new_y = self->x * sin_val + self->y * cos_val;
    self->x = new_x;
    self->y = new_y;
}

void Transformation_scale(Transformation *self, double factor) {
    self->x *= factor;
    self->y *= factor;
    self->z *= factor;
}

void Transformation_translate(Transformation *self, double dx, double dy, double dz) {
    self->x += dx;
    self->y += dy;
    self->z += dz;
}

void apply_transformations(Transformation *obj, double *rotations, int num_rotations, double *scales, int num_scales, double (*translations)[3], int num_translations) {
    for (int i = 0; i < num_rotations; i++) {
        Transformation_rotate(obj, rotations[i]);
    }
    for (int i = 0; i < num_scales; i++) {
        Transformation_scale(obj, scales[i]);
    }
    for (int i = 0; i < num_translations; i++) {
        Transformation_translate(obj, translations[i][0], translations[i][1], translations[i][2]);
    }
}

int main() {
    Transformation obj;
    Transformation_init(&obj, 1, 2, 3);
    double rotations[] = {45, 90, 135};
    double scales[] = {2, 3, 4};
    double translations[][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    apply_transformations(&obj, rotations, 3, scales, 3, translations, 3);
    while (1) {
        apply_transformations(&obj, rotations, 3, scales, 3, translations, 3);
    }
    return 0;
}