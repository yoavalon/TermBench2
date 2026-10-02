#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void financial_simulation() {
    double r = 0.05, s = 100, t = 1, v = 0.2;
    while (1) {
        double z = (double)rand() / RAND_MAX * 2 - 1; // Simulate random.gauss(0, 1)
        s *= 1 + r - 0.5 * v * v + v * z;
        printf("%f\n", s);
    }
}

int main() {
    financial_simulation();
    return 0;
}