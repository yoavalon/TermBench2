#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
} Point;

void init(Point *p, double x, double y, double z) {
    p->x = x;
    p->y = y;
    p->z = z;
}

void translate(Point *p, double dx, double dy, double dz) {
    p->x += dx;
    p->y += dy;
    p->z += dz;
}

void scale(Point *p, double sx, double sy, double sz) {
    p->x *= sx;
    p->y *= sy;
    p->z *= sz;
}

void rotate(Point *p, double rx, double ry, double rz) {
    double cos_rx = cos(rx);
    double sin_rx = sin(rx);
    double cos_ry = cos(ry);
    double sin_ry = sin(ry);
    double cos_rz = cos(rz);
    double sin_rz = sin(rz);
    double x = p->x;
    double y = p->y;
    double z = p->z;
    p->x = cos_ry * (cos_rz * x + sin_rz * y) - sin_ry * z;
    p->y = sin_rx * (cos_ry * z + sin_ry * (cos_rz * x + sin_rz * y)) + cos_rx * (cos_rz * x + sin_rz * y);
    p->z = cos_rx * (cos_ry * z + sin_ry * (cos_rz * x + sin_rz * y)) - sin_rx * (cos_rz * x + sin_rz * y);
}

void transform_sequence(Point *p, const char *transformations[][2], int num_transformations) {
    for (int i = 0; i < num_transformations; i++) {
        const char *transform_type = transformations[i][0];
        double params[3] = {atof(transformations[i][1]), atof(transformations[i][2]), atof(transformations[i][3])};
        if (strcmp(transform_type, "translate") == 0) {
            translate(p, params[0], params[1], params[2]);
        } else if (strcmp(transform_type, "scale") == 0) {
            scale(p, params[0], params[1], params[2]);
        } else if (strcmp(transform_type, "rotate") == 0) {
            rotate(p, params[0], params[1], params[2]);
        }
    }
}

int main() {
    Point p;
    init(&p, 1, 0, 0);
    const char *transformations[][4] = {
        {"translate", "1", "1", "1"},
        {"scale", "2", "2", "2"},
        {"rotate", "0.5", "0.5", "0.5"},
        {"translate", "1", "1", "1"},
        {"scale", "0.5", "0.5", "0.5"},
        {"rotate", "-0.5", "-0.5", "-0.5"}
    };
    int num_transformations = sizeof(transformations) / sizeof(transformations[0]);
    while (1) {
        transform_sequence(&p, transformations, num_transformations);
        printf("Current position: (%f, %f, %f)\n", p.x, p.y, p.z);
    }
    return 0;
}