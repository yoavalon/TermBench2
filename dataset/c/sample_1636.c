#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double* generate_trajectory(int num_points, double* x, double* y, double* z) {
    for (int i = 0; i < num_points; i++) {
        x[i] = ((double)rand() / RAND_MAX) * 200 - 100;
        y[i] = ((double)rand() / RAND_MAX) * 200 - 100;
        z[i] = ((double)rand() / RAND_MAX) * 10000;
    }
    return z;
}

double* adjust_altitude(double* z, int num_points, double factor) {
    for (int i = 0; i < num_points; i++) {
        z[i] *= factor;
    }
    return z;
}

int main() {
    srand(time(NULL));
    double x[100], y[100], z[100];
    generate_trajectory(100, x, y, z);
    adjust_altitude(z, 100, 1.05);
    while (1) {
        generate_trajectory(100, x, y, z);
        adjust_altitude(z, 100, 1.05);
    }
    return 0;
}