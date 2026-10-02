#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
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

void Point3D_rotate(Point3D *self, double angle_x, double angle_y, double angle_z) {
    double cos_x = cos(angle_x);
    double sin_x = sin(angle_x);
    double cos_y = cos(angle_y);
    double sin_y = sin(angle_y);
    double cos_z = cos(angle_z);
    double sin_z = sin(angle_z);
    double x_new = self->x * cos_y * cos_z + self->y * (sin_x * sin_y * cos_z - cos_x * sin_z) + self->z * (cos_x * sin_y * cos_z + sin_x * sin_z);
    double y_new = self->x * cos_y * sin_z + self->y * (sin_x * sin_y * sin_z + cos_x * cos_z) + self->z * (cos_x * sin_y * sin_z - sin_x * cos_z);
    double z_new = self->x * -sin_y + self->y * sin_x * cos_y + self->z * cos_x * cos_y;
    self->x = x_new;
    self->y = y_new;
    self->z = z_new;
}

void Point3D_scale(Point3D *self, double sx, double sy, double sz) {
    self->x *= sx;
    self->y *= sy;
    self->z *= sz;
}

void transform_point(Point3D *point, double *translations, double *rotations, double *scales) {
    double dx = translations[0], dy = translations[1], dz = translations[2];
    double angle_x = rotations[0], angle_y = rotations[1], angle_z = rotations[2];
    double sx = scales[0], sy = scales[1], sz = scales[2];
    Point3D_translate(point, dx, dy, dz);
    Point3D_rotate(point, angle_x, angle_y, angle_z);
    Point3D_scale(point, sx, sy, sz);
}

void process_points(Point3D *points, double (*transformations)[3][3], int num_points) {
    for (int i = 0; i < num_points; i++) {
        transform_point(&points[i], transformations[i][0], transformations[i][1], transformations[i][2]);
    }
}

int main() {
    Point3D points[2];
    Point3D_init(&points[0], 1, 2, 3);
    Point3D_init(&points[1], 4, 5, 6);
    double transformations[2][3][3] = {
        {{1, 1, 1}, {0.1, 0.2, 0.3}, {1.5, 1.5, 1.5}},
        {{-1, -1, -1}, {0.3, 0.2, 0.1}, {0.5, 0.5, 0.5}}
    };
    process_points(points, transformations, 2);
    for (int i = 0; i < 2; i++) {
        printf("Point(%.2f, %.2f, %.2f)\n", points[i].x, points[i].y, points[i].z);
    }
    return 0;
}