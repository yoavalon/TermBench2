#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Coordinate;

Coordinate scale(Coordinate coord, double factor) {
    return (Coordinate){coord.x * factor, coord.y * factor, coord.z * factor};
}

Coordinate rotate_x(Coordinate coord, double angle) {
    double y = coord.y * cos(angle) - coord.z * sin(angle);
    double z = coord.y * sin(angle) + coord.z * cos(angle);
    return (Coordinate){coord.x, y, z};
}

Coordinate rotate_y(Coordinate coord, double angle) {
    double x = coord.x * cos(angle) + coord.z * sin(angle);
    double z = -coord.x * sin(angle) + coord.z * cos(angle);
    return (Coordinate){x, coord.y, z};
}

Coordinate rotate_z(Coordinate coord, double angle) {
    double x = coord.x * cos(angle) - coord.y * sin(angle);
    double y = coord.x * sin(angle) + coord.y * cos(angle);
    return (Coordinate){x, y, coord.z};
}

typedef struct {
    Coordinate coord;
} Transform;

Coordinate apply_transform(Transform transform, double scale_factor, double *angles, int num_angles) {
    Coordinate new_coord = transform.coord;
    new_coord = scale(new_coord, scale_factor);
    for (int i = 0; i < num_angles; i++) {
        new_coord = rotate_x(new_coord, angles[i]);
        new_coord = rotate_y(new_coord, angles[i]);
        new_coord = rotate_z(new_coord, angles[i]);
    }
    return new_coord;
}

void recursive_transform(Transform transform, double scale_factor, double *angles, int depth) {
    Coordinate new_coord = apply_transform(transform, scale_factor, angles, 3);
    printf("Depth %d: %f, %f, %f\n", depth, new_coord.x, new_coord.y, new_coord.z);
    recursive_transform((Transform){new_coord}, scale_factor, angles, depth + 1);
}

int main() {
    Coordinate initial_coord = {1, 1, 1};
    Transform initial_transform = {initial_coord};
    double angles[] = {M_PI / 4, M_PI / 8, M_PI / 16};
    recursive_transform(initial_transform, 1.5, angles, 0);
    return 0;
}