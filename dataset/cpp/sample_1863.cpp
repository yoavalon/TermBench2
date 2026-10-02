#include <iostream>
#include <cmath>
#include <vector>
#include <random>

double monte_carlo_option_pricing(double s, double x, double t, double r, double v, int n) {
    double dt = t / n;
    std::vector<double> st(n + 1);
    st[0] = s;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.0, 1.0);
    for (int i = 1; i <= n; ++i) {
        st[i] = st[i - 1] * exp((r - 0.5 * v * v) * dt + v * sqrt(dt) * d(gen));
    }
    double sum = 0.0;
    for (int i = 0; i <= n; ++i) {
        sum += std::max(st[i] - x, 0.0);
    }
    return exp(-r * t) * (sum / (n + 1));
}

int main() {
    std::cout << monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 1000) << std::endl;
    return 0;
}