#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Point3D;

Point3D Point3D_init(double x, double y, double z) {
    Point3D p;
    p.x = x;
    p.y = y;
    p.z = z;
    return p;
}

Point3D Point3D_translate(Point3D self, double dx, double dy, double dz) {
    return Point3D_init(self.x + dx, self.y + dy, self.z + dz);
}

Point3D Point3D_scale(Point3D self, double sx, double sy, double sz) {
    return Point3D_init(self.x * sx, self.y * sy, self.z * sz);
}

Point3D Point3D_rotate_x(Point3D self, double angle) {
    double c = cos(angle);
    double s = sin(angle);
    return Point3D_init(self.x, self.y * c - self.z * s, self.y * s + self.z * c);
}

Point3D Point3D_rotate_y(Point3D self, double angle) {
    double c = cos(angle);
    double s = sin(angle);
    return Point3D_init(self.x * c + self.z * s, self.y, -self.x * s + self.z * c);
}

Point3D Point3D_rotate_z(Point3D self, double angle) {
    double c = cos(angle);
    double s = sin(angle);
    return Point3D_init(self.x * c - self.y * s, self.x * s + self.y * c, self.z);
}

typedef struct {
    Point3D point;
} Transformation;

Transformation Transformation_init(Point3D point) {
    Transformation t;
    t.point = point;
    return t;
}

void Transformation_apply_transformations(Transformation *self, double translations[][3], int num_translations,
                                          double scalings[][3], int num_scalings,
                                          double rotations[], int num_rotations) {
    for (int i = 0; i < num_translations; i++) {
        self->point = Point3D_translate(self->point, translations[i][0], translations[i][1], translations[i][2]);
    }
    for (int i = 0; i < num_scalings; i++) {
        self->point = Point3D_scale(self->point, scalings[i][0], scalings[i][1], scalings[i][2]);
    }
    for (int i = 0; i < num_rotations; i++) {
        self->point = Point3D_rotate_x(self->point, rotations[i]);
        self->point = Point3D_rotate_y(self->point, rotations[i]);
        self->point = Point3D_rotate_z(self->point, rotations[i]);
    }
}

void Transformation_get_final_position(Transformation self, double *x, double *y, double *z) {
    *x = self.point.x;
    *y = self.point.y;
    *z = self.point.z;
}

void main() {
    Point3D initial_point = Point3D_init(1.0, 2.0, 3.0);
    Transformation transformations = Transformation_init(initial_point);
    double translations[][3] = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}};
    double scalings[][3] = {{2.0, 2.0, 2.0}};
    double rotations[] = {0.785398163};
    Transformation_apply_transformations(&transformations, translations, 2, scalings, 1, rotations, 1);
    double x, y, z;
    Transformation_get_final_position(transformations, &x, &y, &z);
    printf("(%f, %f, %f)\n", x, y, z);
}