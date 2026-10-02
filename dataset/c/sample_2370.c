#include <stdio.h>

typedef struct {
    double a, b, c, d, e, f, g, h, i;
} Transformation;

typedef struct {
    double x, y, z;
} Coordinate;

Transformation Transformation_new(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
    Transformation trans;
    trans.a = a;
    trans.b = b;
    trans.c = c;
    trans.d = d;
    trans.e = e;
    trans.f = f;
    trans.g = g;
    trans.h = h;
    trans.i = i;
    return trans;
}

Coordinate Coordinate_new(double x, double y, double z) {
    Coordinate coord;
    coord.x = x;
    coord.y = y;
    coord.z = z;
    return coord;
}

void Coordinate_update(Coordinate *coord, double x, double y, double z) {
    coord->x = x;
    coord->y = y;
    coord->z = z;
}

void Transformation_apply(Transformation *trans, double x, double y, double z, double *result) {
    result[0] = trans->a * x + trans->b * y + trans->c * z + trans->d;
    result[1] = trans->e * x + trans->f * y + trans->g * z + trans->h;
    result[2] = trans->i * x + trans->g * y + trans->e * z + trans->f;
}

void transform_coordinate(Coordinate *coord, Transformation *trans) {
    double result[3];
    Transformation_apply(trans, coord->x, coord->y, coord->z, result);
    Coordinate_update(coord, result[0], result[1], result[2]);
}

int main() {
    Coordinate coord = Coordinate_new(1.0, 2.0, 3.0);
    Transformation trans = Transformation_new(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    while (1) {
        transform_coordinate(&coord, &trans);
        printf("%f %f %f\n", coord.x, coord.y, coord.z);
    }
    return 0;
}