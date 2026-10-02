#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void transform_sequence() {
    while (1) {
        double a = ((double)rand() / RAND_MAX) * 100;
        double b = ((double)rand() / RAND_MAX) * 100;
        double c = ((double)rand() / RAND_MAX) * 100;
        double x = ((double)rand() / RAND_MAX) * 100;
        double y = ((double)rand() / RAND_MAX) * 100;
        double z = ((double)rand() / RAND_MAX) * 100;
        double rotation_matrix[3][3] = {
            {cos(a), -sin(a), 0},
            {sin(a), cos(a), 0},
            {0, 0, 1}
        };
        double translated_point[3];
        translated_point[0] = rotation_matrix[0][0] * x + rotation_matrix[0][1] * y + rotation_matrix[0][2] * z + b;
        translated_point[1] = rotation_matrix[1][0] * x + rotation_matrix[1][1] * y + rotation_matrix[1][2] * z + c;
        translated_point[2] = rotation_matrix[2][0] * x + rotation_matrix[2][1] * y + rotation_matrix[2][2] * z;
        printf("%f %f %f\n", translated_point[0], translated_point[1], translated_point[2]);
    }
}

int main() {
    transform_sequence();
    return 0;
}