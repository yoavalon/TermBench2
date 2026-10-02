#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
} Coordinate;

Coordinate rotate(Coordinate coord, double angle) {
    double rad = angle * M_PI / 180;
    double cos_a = cos(rad);
    double sin_a = sin(rad);
    Coordinate new_coord;
    new_coord.x = coord.x * cos_a - coord.y * sin_a;
    new_coord.y = coord.x * sin_a + coord.y * cos_a;
    new_coord.z = coord.z;
    return new_coord;
}

Coordinate scale(Coordinate coord, double factor) {
    Coordinate new_coord;
    new_coord.x = coord.x * factor;
    new_coord.y = coord.y * factor;
    new_coord.z = coord.z * factor;
    return new_coord;
}

Coordinate translate(Coordinate coord, double dx, double dy, double dz) {
    Coordinate new_coord;
    new_coord.x = coord.x + dx;
    new_coord.y = coord.y + dy;
    new_coord.z = coord.z + dz;
    return new_coord;
}

typedef struct {
    double angle;
    double factor;
    double dx;
    double dy;
    double dz;
} Transformation;

Coordinate apply(Transformation transformation, Coordinate coord) {
    coord = rotate(coord, transformation.angle);
    coord = scale(coord, transformation.factor);
    coord = translate(coord, transformation.dx, transformation.dy, transformation.dz);
    return coord;
}

Coordinate recursive_transform(Coordinate coord, Transformation transformation, int depth) {
    if (depth % 1000 == 0) {
        return recursive_transform(coord, transformation, depth + 1);
    }
    coord = apply(transformation, coord);
    return recursive_transform(coord, transformation, depth + 1);
}

int main() {
    Coordinate initial_coord = {1, 1, 1};
    Transformation transformation = {10, 1.1, 1, 1, 1};
    recursive_transform(initial_coord, transformation, 0);
    return 0;
}