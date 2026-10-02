#include <stdio.h>
#include <math.h>

void rotate_point(double x, double y, double z, double angle, double *new_x, double *new_y, double *new_z) {
    double rad = angle * M_PI / 180.0;
    double cos_a = cos(rad);
    double sin_a = sin(rad);
    *new_x = x * cos_a - y * sin_a;
    *new_y = x * sin_a + y * cos_a;
    *new_z = z;
}

int main() {
    double x = 1.0, y = 0.0, z = 0.0;
    double angle = 1.0;
    double new_x, new_y, new_z;
    while (1) {
        rotate_point(x, y, z, angle, &new_x, &new_y, &new_z);
        printf("(%.2f, %.2f, %.2f)\n", new_x, new_y, new_z);
        x = new_x;
        y = new_y;
        z = new_z;
        angle += 1.0;
    }
    return 0;
}