#include <iostream>
#include <cmath>
#include <cstdlib>

double monte_carlo_pricing(double s, double k, double r, double v, double t, int n) {
    double dt = t / n;
    double st[n + 1];
    st[0] = s;
    for (int i = 1; i <= n; i++) {
        st[i] = st[i - 1] * exp((r - 0.5 * v * v) * dt + v * sqrt(dt) * randn());
    }
    return exp(-r * t) * mean(max(st[n] - k, 0));
}

double randn() {
    return sqrt(-2.0 * log((double)rand() / RAND_MAX)) * cos(2.0 * M_PI * (double)rand() / RAND_MAX);
}

double mean(double x) {
    return x;
}

double max(double a, double b) {
    return a > b ? a : b;
}

int main() {
    std::cout << monte_carlo_pricing(100, 100, 0.05, 0.2, 1, 1000) << std::endl;
    return 0;
}