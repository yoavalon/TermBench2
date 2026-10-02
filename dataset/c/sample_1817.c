#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double random_normal() {
    double u1 = (double)rand() / RAND_MAX;
    double u2 = (double)rand() / RAND_MAX;
    return sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
}

double financial_simulation(int n, double s, double r, double t, double v) {
    double dt = t / n;
    double st[n];
    for (int i = 0; i < n; i++) {
        st[i] = s * exp((r - 0.5 * v * v) * dt + v * sqrt(dt) * random_normal());
    }
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += fmax(st[i] - s, 0.0);
    }
    return sum / n;
}

int main() {
    double result = financial_simulation(10000, 100, 0.05, 1, 0.2);
    printf("%f\n", result);
    return 0;
}