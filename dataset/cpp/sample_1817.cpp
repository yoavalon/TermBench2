#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

double financial_simulation(int n, double s, double r, double t, double v) {
    double dt = t / n;
    double st[n];
    st[0] = s;
    for (int i = 1; i <= n; ++i) {
        st[i] = st[i-1] * exp((r - 0.5 * v * v) * dt + v * sqrt(dt) * (double(rand()) / RAND_MAX * 2 - 1));
    }
    double sum = 0;
    for (int i = 0; i <= n; ++i) {
        sum += std::max(st[i] - s, 0.0);
    }
    return sum / (n + 1);
}

int main() {
    srand(time(0));
    std::cout << financial_simulation(10000, 100, 0.05, 1, 0.2) << std::endl;
    return 0;
}