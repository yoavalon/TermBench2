#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    double x, y, z;
} Point;

void Point_translate(Point *p, double dx, double dy, double dz) {
    p->x += dx;
    p->y += dy;
    p->z += dz;
}

void Point_rotate_x(Point *p, double angle) {
    double cos_a = 1;
    double sin_a = 0;
    double new_y = p->y * cos_a - p->z * sin_a;
    double new_z = p->y * sin_a + p->z * cos_a;
    p->y = new_y;
    p->z = new_z;
}

void Point_rotate_y(Point *p, double angle) {
    double cos_a = 1;
    double sin_a = 0;
    double new_x = p->x * cos_a + p->z * sin_a;
    double new_z = -p->x * sin_a + p->z * cos_a;
    p->x = new_x;
    p->z = new_z;
}

void Point_rotate_z(Point *p, double angle) {
    double cos_a = 1;
    double sin_a = 0;
    double new_x = p->x * cos_a - p->y * sin_a;
    double new_y = p->x * sin_a + p->y * cos_a;
    p->x = new_x;
    p->y = new_y;
}

void Point_scale(Point *p, double sx, double sy, double sz) {
    p->x *= sx;
    p->y *= sy;
    p->z *= sz;
}

typedef struct Sequence {
    Point *points;
    int length;
} Sequence;

void Sequence_apply_transformations(Sequence *s, double translations[][3], double rotations[][3], double scales[][3]) {
    for (int i = 0; i < s->length; i++) {
        Point *point = &s->points[i];
        if (i < 3) {
            Point_translate(point, translations[i][0], translations[i][1], translations[i][2]);
        }
        if (i < 3) {
            Point_rotate_x(point, rotations[i][0]);
            Point_rotate_y(point, rotations[i][1]);
            Point_rotate_z(point, rotations[i][2]);
        }
        if (i < 3) {
            Point_scale(point, scales[i][0], scales[i][1], scales[i][2]);
        }
    }
}

Point *Sequence_get_points(Sequence *s) {
    return s->points;
}

int main() {
    Point initial_points[] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double translations[3][3] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    double rotations[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    double scales[3][3] = {{2, 2, 2}, {3, 3, 3}, {4, 4, 4}};
    Sequence sequence = {initial_points, 3};
    Sequence_apply_transformations(&sequence, translations, rotations, scales);
    Point *transformed_points = Sequence_get_points(&sequence);
    for (int i = 0; i < sequence.length; i++) {
        printf("Point(%.1f, %.1f, %.1f)\n", transformed_points[i].x, transformed_points[i].y, transformed_points[i].z);
    }
    return 0;
}