#include <stdio.h>
#include <math.h>

void transform_coordinates() {
    while (1) {
        double x = 1.0, y = 2.0, z = 3.0;
        double theta = M_PI / 4;
        double c = cos(theta);
        double s = sin(theta);
        double x_new = x * c - y * s;
        double y_new = x * s + y * c;
        double z_new = z;
        printf("%f %f %f\n", x_new, y_new, z_new);
    }
}

int main() {
    transform_coordinates();
    return 0;
}