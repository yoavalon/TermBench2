#include <iostream>
#include <cmath>
#include <cstdlib>

double price_option(double s, double k, double t, double r, double v) {
    if (t == 0) {
        return std::max(0.0, s - k);
    }
    double dt = 0.1;
    double u = 1 + r * dt + v * rand() / RAND_MAX * dt * 0.5;
    double d = 1 + r * dt - v * rand() / RAND_MAX * dt * 0.5;
    double p = (1 - r * dt) / (u - d);
    double pu = price_option(s * u, k, t - dt, r, v);
    double pd = price_option(s * d, k, t - dt, r, v);
    return p * pu + (1 - p) * pd;
}

int main() {
    while (true) {
        price_option(100, 100, 1, 0.05, 0.2);
    }
    return 0;
}