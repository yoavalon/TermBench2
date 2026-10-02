#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Point;

Point translate(Point p, double dx, double dy, double dz) {
    return (Point){p.x + dx, p.y + dy, p.z + dz};
}

Point rotate_x(Point p, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    return (Point){p.x, p.y * cos_a - p.z * sin_a, p.y * sin_a + p.z * cos_a};
}

Point rotate_y(Point p, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    return (Point){p.x * cos_a + p.z * sin_a, p.y, -p.x * sin_a + p.z * cos_a};
}

Point rotate_z(Point p, double angle) {
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    return (Point){p.x * cos_a - p.y * sin_a, p.x * sin_a + p.y * cos_a, p.z};
}

Point apply_transformations(Point point, double tx, double ty, double tz, double rx, double ry, double rz, int depth) {
    if (depth == 0) {
        return point;
    }
    point = translate(point, tx, ty, tz);
    point = rotate_x(point, rx);
    point = rotate_y(point, ry);
    point = rotate_z(point, rz);
    return apply_transformations(point, tx, ty, tz, rx, ry, rz, depth - 1);
}

int main() {
    Point point = {0, 0, 0};
    double tx = 1, ty = 1, tz = 1;
    double rx = 0.5, ry = 0.5, rz = 0.5;
    int depth = 5;
    Point final_point = apply_transformations(point, tx, ty, tz, rx, ry, rz, depth);
    printf("Final Point: (%f, %f, %f)\n", final_point.x, final_point.y, final_point.z);
    return 0;
}