#include <stdio.h>

void simulate() {
    double x = 1.0, y = 0.0, z = 0.0;
    while (1) {
        double next_x = y;
        double next_y = z;
        double next_z = 3.9 * x * (1 - x) + z;
        x = next_x;
        y = next_y;
        z = next_z;
        printf("(%.1f, %.1f, %.1f)\n", x, y, z);
    }
}

int main() {
    simulate();
    return 0;
}