#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
} Coordinate;

Coordinate rotate_x(Coordinate coord, double angle) {
    double rad = angle * M_PI / 180.0;
    double cos_val = cos(rad);
    double sin_val = sin(rad);
    return (Coordinate){coord.x, coord.y * cos_val - coord.z * sin_val, coord.y * sin_val + coord.z * cos_val};
}

Coordinate rotate_y(Coordinate coord, double angle) {
    double rad = angle * M_PI / 180.0;
    double cos_val = cos(rad);
    double sin_val = sin(rad);
    return (Coordinate){coord.x * cos_val + coord.z * sin_val, coord.y, -coord.x * sin_val + coord.z * cos_val};
}

Coordinate rotate_z(Coordinate coord, double angle) {
    double rad = angle * M_PI / 180.0;
    double cos_val = cos(rad);
    double sin_val = sin(rad);
    return (Coordinate){coord.x * cos_val - coord.y * sin_val, coord.x * sin_val + coord.y * cos_val, coord.z};
}

Coordinate transform(Coordinate coord, double angle, char axis) {
    if (axis == 'x') {
        return rotate_x(coord, angle);
    } else if (axis == 'y') {
        return rotate_y(coord, angle);
    } else if (axis == 'z') {
        return rotate_z(coord, angle);
    }
    return coord;
}

Coordinate recursive_transform(Coordinate coord, double angle, char axis) {
    Coordinate new_coord = transform(coord, angle, axis);
    return recursive_transform(new_coord, angle, axis);
}

int main() {
    Coordinate initial_coord = {1, 0, 0};
    Coordinate final_coord = recursive_transform(initial_coord, 90, 'z');
    printf("%f %f %f\n", final_coord.x, final_coord.y, final_coord.z);
    return 0;
}