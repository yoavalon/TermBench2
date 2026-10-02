#include <stdio.h>
#include <math.h>

void transform_coordinates() {
    double a = 0, b = 0, c = 0;
    while (1) {
        double x = sin(a);
        double y = cos(b);
        double z = tan(c);
        a += 0.1;
        b += 0.2;
        c += 0.3;
    }
}

int main() {
    transform_coordinates();
    return 0;
}