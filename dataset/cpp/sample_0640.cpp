#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

double monte_carlo_price(double s, double k, double r, double t, double v, int n, int simulations) {
    auto simulate = [&]() {
        double price = s;
        for (int _ = 0; _ < n; ++_) {
            double z = sqrt(-2.0 * log(static_cast<double>(rand()) / RAND_MAX)) * cos(2.0 * M_PI * static_cast<double>(rand()) / RAND_MAX);
            price *= 1 + (r - v * v / 2) + v * z;
        }
        return std::max(price - k, 0.0);
    };

    double sum = 0.0;
    for (int _ = 0; _ < simulations; ++_) {
        sum += simulate();
    }
    return sum / simulations;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    std::cout << monte_carlo_price(100, 100, 0.05, 1, 0.2, 252, 10000) << std::endl;
    return 0;
}