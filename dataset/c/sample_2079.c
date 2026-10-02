#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Point;

void Point_init(Point *self, double x, double y, double z) {
    self->x = x;
    self->y = y;
    self->z = z;
}

void Point_translate(Point *self, double dx, double dy, double dz) {
    self->x += dx;
    self->y += dy;
    self->z += dz;
}

void Point_rotate(Point *self, double angle_x, double angle_y, double angle_z) {
    double cos_x = cos(angle_x);
    double sin_x = sin(angle_x);
    double cos_y = cos(angle_y);
    double sin_y = sin(angle_y);
    double cos_z = cos(angle_z);
    double sin_z = sin(angle_z);
    double x = self->x;
    double y = self->y;
    double z = self->z;
    self->x = x * cos_y * cos_z + y * (-cos_x * sin_z + sin_x * sin_y * cos_z) + z * (sin_x * sin_z + cos_x * sin_y * cos_z);
    self->y = x * cos_y * sin_z + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (-sin_x * cos_z + cos_x * sin_y * sin_z);
    self->z = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
}

void transform_point(Point *point, double *translation, double *rotation) {
    Point_translate(point, translation[0], translation[1], translation[2]);
    Point_rotate(point, rotation[0], rotation[1], rotation[2]);
}

int main() {
    Point p;
    Point_init(&p, 1.0, 2.0, 3.0);
    double translation[] = {4.0, 5.0, 6.0};
    double rotation[] = {0.5, 1.0, 1.5};
    transform_point(&p, translation, rotation);
    printf("%f %f %f\n", p.x, p.y, p.z);
    return 0;
}