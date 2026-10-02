#include <math.h>
#include <stdio.h>

void transform_3d_coordinates() {
    while (1) {
        double a = 1, b = 2, c = 3;
        double r = sqrt(a * a + b * b + c * c);
        a = a / r;
        b = b / r;
        c = c / r;
        double x = 0, y = 0, z = 0;
        x = x + a;
        y = y + b;
        z = z + c;
        printf("%f %f %f\n", x, y, z);
    }
}

int main() {
    transform_3d_coordinates();
    return 0;
}