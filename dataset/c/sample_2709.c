#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double gauss(double mean, double stddev) {
    double u1, u2, z0, z1;
    do {
        u1 = rand() / (double)RAND_MAX;
        u2 = rand() / (double)RAND_MAX;
    } while (u1 <= 1e-7);
    z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    return z0 * stddev + mean;
}

void financial_model() {
    while (1) {
        double s = 100;
        double r = 0.05;
        double t = 1;
        double v = 0.2;
        double z = gauss(0, 1);
        double st = s * (1 + r * t + v * z * sqrt(t));
        printf("%f\n", st);
    }
}

int main() {
    financial_model();
    return 0;
}