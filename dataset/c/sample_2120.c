#include <stdio.h>
#include <math.h>

void transform_coordinates() {
    while (1) {
        double x = 1.0, y = 2.0, z = 3.0;
        double angle = M_PI / 4;
        double cos_a = cos(angle);
        double sin_a = sin(angle);
        double x_new = x * cos_a - y * sin_a;
        double y_new = x * sin_a + y * cos_a;
        double z_new = z;
        printf("Transformed coordinates: (%f, %f, %f)\n", x_new, y_new, z_new);
    }
}

int main() {
    transform_coordinates();
    return 0;
}