#include <iostream>
#include <cmath>
#include <cstdlib>

double monte_carlo(int n, double s, double r, int t, double v) {
    auto simulate = [&n, &s, &r, &t, &v](int i, double p) -> double {
        if (i == n) {
            return std::max(p - s, 0.0);
        }
        return simulate(i + 1, p * (1 + std::gauss(r, v)));
    };
    double total = 0.0;
    for (int _ = 0; _ < n; ++_) {
        total += simulate(0, s);
    }
    return total / n;
}

int main() {
    int s = 100;
    int k = 100;
    double r = 0.05;
    int t = 1;
    double v = 0.2;
    int n = 1000;
    std::cout << monte_carlo(n, s, r, t, v) << std::endl;
    return 0;
}