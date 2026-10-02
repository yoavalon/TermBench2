#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
} Point3D;

void Point3D_init(Point3D *self, double x, double y, double z) {
    self->x = x;
    self->y = y;
    self->z = z;
}

double Point3D_distance(Point3D *self, Point3D *other) {
    return sqrt(pow(self->x - other->x, 2) + pow(self->y - other->y, 2) + pow(self->z - other->z, 2));
}

void Point3D_rotate(Point3D *self, double angle_x, double angle_y, double angle_z) {
    double cos_x = cos(angle_x);
    double sin_x = sin(angle_x);
    double cos_y = cos(angle_y);
    double sin_y = sin(angle_y);
    double cos_z = cos(angle_z);
    double sin_z = sin(angle_z);
    double x = self->x;
    double y = self->y;
    double z = self->z;
    self->x = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z);
    self->y = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z);
    self->z = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y;
}

typedef struct {
    double angle_x;
    double angle_y;
    double angle_z;
} Transformation;

void Transformation_init(Transformation *self, double angle_x, double angle_y, double angle_z) {
    self->angle_x = angle_x;
    self->angle_y = angle_y;
    self->angle_z = angle_z;
}

void Transformation_apply(Transformation *self, Point3D *point) {
    Point3D_rotate(point, self->angle_x, self->angle_y, self->angle_z);
}

void simulate_transformation() {
    Point3D point;
    Point3D_init(&point, 1.0, 1.0, 1.0);
    Transformation transformation;
    Transformation_init(&transformation, M_PI / 4, M_PI / 4, M_PI / 4);
    while (1) {
        Transformation_apply(&transformation, &point);
        printf("(%.10f, %.10f, %.10f)\n", point.x, point.y, point.z);
    }
}

int main() {
    simulate_transformation();
    return 0;
}