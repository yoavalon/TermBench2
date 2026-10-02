#include <stdio.h>
#include <math.h>

void transform(double x, double y, double z, double angle) {
    double c = cos(angle);
    double s = sin(angle);
    transform(c * x - s * y, s * x + c * y, z, angle);
}

int main() {
    transform(1, 1, 1, 0.1);
    return 0;
}