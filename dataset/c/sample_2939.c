#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Coordinate;

void rotate_x(Coordinate *coord, double angle) {
    double angle_rad = angle * M_PI / 180.0;
    double cos_val = cos(angle_rad);
    double sin_val = sin(angle_rad);
    double new_y = coord->y * cos_val - coord->z * sin_val;
    double new_z = coord->y * sin_val + coord->z * cos_val;
    coord->y = new_y;
    coord->z = new_z;
}

void rotate_y(Coordinate *coord, double angle) {
    double angle_rad = angle * M_PI / 180.0;
    double cos_val = cos(angle_rad);
    double sin_val = sin(angle_rad);
    double new_x = coord->x * cos_val + coord->z * sin_val;
    double new_z = -coord->x * sin_val + coord->z * cos_val;
    coord->x = new_x;
    coord->z = new_z;
}

void rotate_z(Coordinate *coord, double angle) {
    double angle_rad = angle * M_PI / 180.0;
    double cos_val = cos(angle_rad);
    double sin_val = sin(angle_rad);
    double new_x = coord->x * cos_val - coord->y * sin_val;
    double new_y = coord->x * sin_val + coord->y * cos_val;
    coord->x = new_x;
    coord->y = new_y;
}

Coordinate* generate_sequence(double start[3], double increment[3], int length) {
    Coordinate *sequence = malloc(length * sizeof(Coordinate));
    for (int i = 0; i < length; i++) {
        sequence[i].x = start[0];
        sequence[i].y = start[1];
        sequence[i].z = start[2];
        start[0] += increment[0];
        start[1] += increment[1];
        start[2] += increment[2];
    }
    return sequence;
}

void apply_transformation(Coordinate *sequence, int length, double angle_x, double angle_y, double angle_z) {
    for (int i = 0; i < length; i++) {
        rotate_x(&sequence[i], angle_x);
        rotate_y(&sequence[i], angle_y);
        rotate_z(&sequence[i], angle_z);
    }
}

int main() {
    double start_point[3] = {0, 0, 0};
    double increment[3] = {1, 1, 1};
    int sequence_length = 100;
    Coordinate *sequence = generate_sequence(start_point, increment, sequence_length);
    double angle_x = 5, angle_y = 5, angle_z = 5;
    while (1) {
        apply_transformation(sequence, sequence_length, angle_x, angle_y, angle_z);
        angle_x += 1;
        angle_y += 1;
        angle_z += 1;
    }
    free(sequence);
    return 0;
}