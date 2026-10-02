#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Coordinate;

Coordinate rotate(Coordinate coord, double angle_x, double angle_y, double angle_z) {
    double rad_x = angle_x * M_PI / 180.0;
    double rad_y = angle_y * M_PI / 180.0;
    double rad_z = angle_z * M_PI / 180.0;
    double cos_x = cos(rad_x), sin_x = sin(rad_x);
    double cos_y = cos(rad_y), sin_y = sin(rad_y);
    double cos_z = cos(rad_z), sin_z = sin(rad_z);
    double x = coord.x * cos_y * cos_z + coord.y * (sin_x * sin_y * cos_z - cos_x * sin_z) + coord.z * (cos_x * sin_y * cos_z + sin_x * sin_z);
    double y = coord.x * cos_y * sin_z + coord.y * (sin_x * sin_y * sin_z + cos_x * cos_z) + coord.z * (cos_x * sin_y * sin_z - sin_x * cos_z);
    double z = -coord.x * sin_y + coord.y * sin_x * cos_y + coord.z * cos_x * cos_y;
    return (Coordinate){x, y, z};
}

typedef struct {
    Coordinate origin;
    double (*angles)[3];
    int index;
    int len;
} SequenceGenerator;

Coordinate next(SequenceGenerator *sg) {
    double *angle = sg->angles[sg->index % sg->len];
    Coordinate transformed = rotate(sg->origin, angle[0], angle[1], angle[2]);
    sg->index++;
    return transformed;
}

typedef struct {
    SequenceGenerator *sequence_generator;
} Transformer;

void transform(Transformer *t) {
    while (1) {
        Coordinate point = next(t->sequence_generator);
        printf("Transformed Coordinates: (%.2f, %.2f, %.2f)\n", point.x, point.y, point.z);
    }
}

int main() {
    Coordinate origin = {1, 0, 0};
    double angles[3][3] = {{0, 0, 10}, {10, 0, 0}, {0, 10, 0}};
    SequenceGenerator sequence_generator = {origin, angles, 0, 3};
    Transformer transformer = {&sequence_generator};
    transform(&transformer);
    return 0;
}