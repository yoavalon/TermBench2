#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double simulate(int i, double p, int n, double s, double r, double v) {
    if (i == n) {
        return fmax(p - s, 0);
    }
    double gauss = r + v * sqrt(-2 * log((double)rand() / RAND_MAX)) * cos(2 * M_PI * (double)rand() / RAND_MAX);
    return simulate(i + 1, p * (1 + gauss), n, s, r, v);
}

double monte_carlo(int n, double s, double r, double t, double v) {
    double sum = 0;
    for (int _ = 0; _ < n; _++) {
        sum += simulate(0, s, n, s, r, v);
    }
    return sum / n;
}

int main() {
    int s = 100;
    int k = 100;
    double r = 0.05;
    double t = 1;
    double v = 0.2;
    int n = 1000;
    srand(time(0));
    printf("%f\n", monte_carlo(n, s, r, t, v));
    return 0;
}