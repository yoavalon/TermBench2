#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
} Point;

void translate(Point *self, double a, double b, double c) {
    self->x += a;
    self->y += b;
    self->z += c;
}

void rotate_x(Point *self, double angle) {
    double cos_angle = cos(angle);
    double sin_angle = sin(angle);
    double new_y = self->y * cos_angle - self->z * sin_angle;
    double new_z = self->y * sin_angle + self->z * cos_angle;
    self->y = new_y;
    self->z = new_z;
}

void rotate_y(Point *self, double angle) {
    double cos_angle = cos(angle);
    double sin_angle = sin(angle);
    double new_x = self->x * cos_angle + self->z * sin_angle;
    double new_z = -self->x * sin_angle + self->z * cos_angle;
    self->x = new_x;
    self->z = new_z;
}

void rotate_z(Point *self, double angle) {
    double cos_angle = cos(angle);
    double sin_angle = sin(angle);
    double new_x = self->x * cos_angle - self->y * sin_angle;
    double new_y = self->x * sin_angle + self->y * cos_angle;
    self->x = new_x;
    self->y = new_y;
}

typedef struct {
    Point point;
} Transformations;

void apply_transformations(Transformations *self, double a, double b, double c, double angle_x, double angle_y, double angle_z) {
    translate(&self->point, a, b, c);
    rotate_x(&self->point, angle_x);
    rotate_y(&self->point, angle_y);
    rotate_z(&self->point, angle_z);
}

void recursive_transform(Transformations *transform_obj, double angle_increment) {
    angle_increment = angle_increment * M_PI / 180.0;
    apply_transformations(transform_obj, 1, 1, 1, angle_increment, angle_increment, angle_increment);
    recursive_transform(transform_obj, angle_increment);
}

int main() {
    Point point = {0, 0, 0};
    Transformations transformations = {point};
    recursive_transform(&transformations, 1);
    return 0;
}