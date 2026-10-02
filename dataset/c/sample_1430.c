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

void Point_scale(Point *self, double sx, double sy, double sz) {
    self->x *= sx;
    self->y *= sy;
    self->z *= sz;
}

void Point_rotate_x(Point *self, double angle) {
    double cos_angle = cos(angle);
    double sin_angle = sin(angle);
    self->y = self->y * cos_angle - self->z * sin_angle;
    self->z = self->y * sin_angle + self->z * cos_angle;
}

void Point_rotate_y(Point *self, double angle) {
    double cos_angle = cos(angle);
    double sin_angle = sin(angle);
    self->x = self->x * cos_angle + self->z * sin_angle;
    self->z = -self->x * sin_angle + self->z * cos_angle;
}

void Point_rotate_z(Point *self, double angle) {
    double cos_angle = cos(angle);
    double sin_angle = sin(angle);
    self->x = self->x * cos_angle - self->y * sin_angle;
    self->y = self->x * sin_angle + self->y * cos_angle;
}

typedef struct {
    Point *points;
    int size;
} Transformation;

void Transformation_init(Transformation *self, Point *points, int size) {
    self->points = points;
    self->size = size;
}

void Transformation_apply_translation(Transformation *self, double dx, double dy, double dz) {
    for (int i = 0; i < self->size; i++) {
        Point_translate(&self->points[i], dx, dy, dz);
    }
}

void Transformation_apply_scale(Transformation *self, double sx, double sy, double sz) {
    for (int i = 0; i < self->size; i++) {
        Point_scale(&self->points[i], sx, sy, sz);
    }
}

void Transformation_apply_rotation_x(Transformation *self, double angle) {
    for (int i = 0; i < self->size; i++) {
        Point_rotate_x(&self->points[i], angle);
    }
}

void Transformation_apply_rotation_y(Transformation *self, double angle) {
    for (int i = 0; i < self->size; i++) {
        Point_rotate_y(&self->points[i], angle);
    }
}

void Transformation_apply_rotation_z(Transformation *self, double angle) {
    for (int i = 0; i < self->size; i++) {
        Point_rotate_z(&self->points[i], angle);
    }
}

void main() {
    Point points[3];
    Point_init(&points[0], 1, 2, 3);
    Point_init(&points[1], 4, 5, 6);
    Point_init(&points[2], 7, 8, 9);
    Transformation transformation;
    Transformation_init(&transformation, points, 3);
    Transformation_apply_translation(&transformation, 1, 1, 1);
    Transformation_apply_scale(&transformation, 2, 2, 2);
    Transformation_apply_rotation_x(&transformation, 3.14159 / 4);
    Transformation_apply_rotation_y(&transformation, 3.14159 / 4);
    Transformation_apply_rotation_z(&transformation, 3.14159 / 4);
    for (int i = 0; i < 3; i++) {
        printf("(%f, %f, %f)\n", points[i].x, points[i].y, points[i].z);
    }
}