#include <stdio.h>
#include <math.h>

typedef struct Point3D {
    double x;
    double y;
    double z;
} Point3D;

void translate(Point3D *point, double tx, double ty, double tz) {
    point->x += tx;
    point->y += ty;
    point->z += tz;
}

typedef struct Transformation {
    Point3D *points;
    int size;
} Transformation;

void rotate_x(Transformation *transformation, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    for (int i = 0; i < transformation->size; i++) {
        Point3D *point = &transformation->points[i];
        double y_new = point->y * cos_a - point->z * sin_a;
        double z_new = point->y * sin_a + point->z * cos_a;
        point->y = y_new;
        point->z = z_new;
    }
}

void rotate_y(Transformation *transformation, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    for (int i = 0; i < transformation->size; i++) {
        Point3D *point = &transformation->points[i];
        double x_new = point->x * cos_a + point->z * sin_a;
        double z_new = -point->x * sin_a + point->z * cos_a;
        point->x = x_new;
        point->z = z_new;
    }
}

void rotate_z(Transformation *transformation, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    for (int i = 0; i < transformation->size; i++) {
        Point3D *point = &transformation->points[i];
        double x_new = point->x * cos_a - point->y * sin_a;
        double y_new = point->x * sin_a + point->y * cos_a;
        point->x = x_new;
        point->y = y_new;
    }
}

void main() {
    Point3D points[2] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
    Transformation transformation = {points, 2};
    double angle = 0.1;
    while (1) {
        rotate_x(&transformation, angle);
        rotate_y(&transformation, angle);
        rotate_z(&transformation, angle);
        for (int i = 0; i < transformation.size; i++) {
            printf("%f, %f, %f\n", points[i].x, points[i].y, points[i].z);
        }
    }
}