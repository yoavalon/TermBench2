#include <stdio.h>
#include <math.h>

typedef struct Point {
    double x;
    double y;
    double z;
} Point;

void Point_init(Point *self, double x, double y, double z) {
    self->x = x;
    self->y = y;
    self->z = z;
}

void Point_repr(const Point *self) {
    printf("Point(%.2f, %.2f, %.2f)", self->x, self->y, self->z);
}

typedef struct Transformation {
} Transformation;

Point Transformation_rotate(const Transformation *self, const Point *point, double angle_x, double angle_y, double angle_z) {
    double cos_x = cos(angle_x);
    double sin_x = sin(angle_x);
    double cos_y = cos(angle_y);
    double sin_y = sin(angle_y);
    double cos_z = cos(angle_z);
    double sin_z = sin(angle_z);
    double x = point->x * (cos_y * cos_z) + point->y * (cos_y * sin_z - sin_x * sin_y * cos_z) + point->z * (cos_y * sin_x * sin_z + cos_x * cos_z);
    double y = point->x * (sin_y * cos_z) + point->y * (sin_y * sin_z + sin_x * cos_y * cos_z) + point->z * (sin_y * sin_x * sin_z - cos_x * sin_z);
    double z = point->x * (-sin_x * cos_y) + point->y * (sin_x * sin_y) + point->z * cos_x;
    Point result;
    Point_init(&result, x, y, z);
    return result;
}

Point Transformation_translate(const Transformation *self, const Point *point, double dx, double dy, double dz) {
    Point result;
    Point_init(&result, point->x + dx, point->y + dy, point->z + dz);
    return result;
}

Point Transformation_scale(const Transformation *self, const Point *point, double sx, double sy, double sz) {
    Point result;
    Point_init(&result, point->x * sx, point->y * sy, point->z * sz);
    return result;
}

typedef struct CoordinateSystem {
    Point origin;
    Transformation transformation;
} CoordinateSystem;

void CoordinateSystem_init(CoordinateSystem *self, const Point *origin, const Transformation *transformation) {
    self->origin = *origin;
    self->transformation = *transformation;
}

Point CoordinateSystem_apply_transformations(CoordinateSystem *self, const Point *point, double angle_x, double angle_y, double angle_z, double dx, double dy, double dz, double sx, double sy, double sz) {
    Point rotated = Transformation_rotate(&self->transformation, point, angle_x, angle_y, angle_z);
    Point translated = Transformation_translate(&self->transformation, &rotated, dx, dy, dz);
    Point scaled = Transformation_scale(&self->transformation, &translated, sx, sy, sz);
    return scaled;
}

int main() {
    Point origin;
    Point_init(&origin, 0, 0, 0);
    Transformation transformation;
    CoordinateSystem coordinate_system;
    CoordinateSystem_init(&coordinate_system, &origin, &transformation);
    Point initial_point;
    Point_init(&initial_point, 1, 2, 3);
    double angle_x = 0.5, angle_y = 0.5, angle_z = 0.5;
    double dx = 1, dy = 1, dz = 1;
    double sx = 2, sy = 2, sz = 2;
    Point transformed_point = CoordinateSystem_apply_transformations(&coordinate_system, &initial_point, angle_x, angle_y, angle_z, dx, dy, dz, sx, sy, sz);
    Point_repr(&transformed_point);
    return 0;
}