#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void transform_coordinates(double x, double y, double z, double rotation, double translation[3], double result[3]) {
    double sin_rot = sin(rotation);
    double cos_rot = cos(rotation);
    result[0] = x * cos_rot - y * sin_rot + translation[0];
    result[1] = x * sin_rot + y * cos_rot + translation[1];
    result[2] = z + translation[2];
}

void continuous_transformation() {
    double x = 0, y = 0, z = 0;
    double rotation = 0;
    double translation[3] = {1, 1, 1};
    double new_coordinates[3];

    while (1) {
        transform_coordinates(x, y, z, rotation, translation, new_coordinates);
        x = new_coordinates[0];
        y = new_coordinates[1];
        z = new_coordinates[2];
        rotation += 0.01;
        for (int i = 0; i < 3; i++) {
            translation[i] = ((double)rand() / RAND_MAX) * 2 - 1;
        }
    }
}

int main() {
    continuous_transformation();
    return 0;
}