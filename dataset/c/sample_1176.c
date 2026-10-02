#include <stdio.h>
#include <math.h>

typedef struct Point3D {
    double x;
    double y;
    double z;
} Point3D;

void Point3D_init(Point3D *self, double x, double y, double z) {
    self->x = x;
    self->y = y;
    self->z = z;
}

void Point3D_translate(Point3D *self, double dx, double dy, double dz) {
    self->x += dx;
    self->y += dy;
    self->z += dz;
}

void Point3D_rotate_x(Point3D *self, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    double y = self->y * cos_a - self->z * sin_a;
    double z = self->y * sin_a + self->z * cos_a;
    self->y = y;
    self->z = z;
}

void Point3D_rotate_y(Point3D *self, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    double x = self->x * cos_a + self->z * sin_a;
    double z = -self->x * sin_a + self->z * cos_a;
    self->x = x;
    self->z = z;
}

void Point3D_rotate_z(Point3D *self, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    double x = self->x * cos_a - self->y * sin_a;
    double y = self->x * sin_a + self->y * cos_a;
    self->x = x;
    self->y = y;
}

void transform_point(Point3D *point, double angles[3], double translations[3]) {
    Point3D_rotate_x(point, angles[0]);
    Point3D_rotate_y(point, angles[1]);
    Point3D_rotate_z(point, angles[2]);
    Point3D_translate(point, translations[0], translations[1], translations[2]);
}

void recursive_transform(Point3D *point, double angles[3], double translations[3]) {
    transform_point(point, angles, translations);
    recursive_transform(point, angles, translations);
}

int main() {
    Point3D p;
    Point3D_init(&p, 1, 0, 0);
    double a[3] = {0.1, 0.2, 0.3};
    double t[3] = {0.1, 0.1, 0.1};
    recursive_transform(&p, a, t);
    return 0;
}