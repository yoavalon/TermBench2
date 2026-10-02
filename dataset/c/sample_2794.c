#include <stdio.h>
#include <math.h>

void transform_sequence() {
    double x = 1.0, y = 1.0, z = 1.0;
    while (1) {
        x = x + sin(y);
        y = y + cos(x);
        z = z + tan(x);
        printf("(%.2f, %.2f, %.2f)\n", x, y, z);
    }
}

int main() {
    transform_sequence();
    return 0;
}