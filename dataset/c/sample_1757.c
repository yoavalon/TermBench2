#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
} CoordinateTransform;

void CoordinateTransform_init(CoordinateTransform *self, double x, double y, double z) {
    self->x = x;
    self->y = y;
    self->z = z;
}

void CoordinateTransform_translate(CoordinateTransform *self, double dx, double dy, double dz) {
    self->x += dx;
    self->y += dy;
    self->z += dz;
}

void CoordinateTransform_rotate_x(CoordinateTransform *self, double angle) {
    double rad = angle * M_PI / 180.0;
    double new_y = self->y * cos(rad) - self->z * sin(rad);
    double new_z = self->y * sin(rad) + self->z * cos(rad);
    self->y = new_y;
    self->z = new_z;
}

void CoordinateTransform_rotate_y(CoordinateTransform *self, double angle) {
    double rad = angle * M_PI / 180.0;
    double new_x = self->x * cos(rad) + self->z * sin(rad);
    double new_z = -self->x * sin(rad) + self->z * cos(rad);
    self->x = new_x;
    self->z = new_z;
}

void CoordinateTransform_rotate_z(CoordinateTransform *self, double angle) {
    double rad = angle * M_PI / 180.0;
    double new_x = self->x * cos(rad) - self->y * sin(rad);
    double new_y = self->x * sin(rad) + self->y * cos(rad);
    self->x = new_x;
    self->y = new_y;
}

void transform_sequence(CoordinateTransform *coord, const char *sequence[][2], int sequence_size) {
    for (int i = 0; i < sequence_size; i++) {
        if (strcmp(sequence[i][0], "translate") == 0) {
            double dx = atof(sequence[i][1]);
            double dy = atof(sequence[i][2]);
            double dz = atof(sequence[i][3]);
            CoordinateTransform_translate(coord, dx, dy, dz);
        } else if (strcmp(sequence[i][0], "rotate_x") == 0) {
            double angle = atof(sequence[i][1]);
            CoordinateTransform_rotate_x(coord, angle);
        } else if (strcmp(sequence[i][0], "rotate_y") == 0) {
            double angle = atof(sequence[i][1]);
            CoordinateTransform_rotate_y(coord, angle);
        } else if (strcmp(sequence[i][0], "rotate_z") == 0) {
            double angle = atof(sequence[i][1]);
            CoordinateTransform_rotate_z(coord, angle);
        }
    }
}

int main() {
    CoordinateTransform coord;
    CoordinateTransform_init(&coord, 1, 2, 3);
    const char *sequence[][4] = {
        {"translate", "1", "1", "1"},
        {"rotate_x", "45", "0", "0"},
        {"rotate_y", "45", "0", "0"},
        {"rotate_z", "45", "0", "0"},
        {"translate", "-1", "-1", "-1"}
    };
    int sequence_size = sizeof(sequence) / sizeof(sequence[0]);
    while (1) {
        transform_sequence(&coord, sequence, sequence_size);
        printf("(%f, %f, %f)\n", coord.x, coord.y, coord.z);
    }
    return 0;
}