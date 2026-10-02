#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double monte_carlo_pricing(double s, double k, double r, double v, double t, int n) {
    double dt = t / n;
    double st[n + 1];
    st[0] = s;
    for (int i = 1; i <= n; i++) {
        st[i] = st[i - 1] * exp((r - 0.5 * v * v) * dt + v * sqrt(dt) * ((double)rand() / RAND_MAX * 2 - 1));
    }
    double sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += fmax(st[n] - k, 0);
    }
    return exp(-r * t) * (sum / (n + 1));
}

int main() {
    srand(time(0));
    double result = monte_carlo_pricing(100, 100, 0.05, 0.2, 1, 1000);
    printf("%f\n", result);
    return 0;
}