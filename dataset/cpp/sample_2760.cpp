#include <iostream>
#include <cmath>
#include <cstdlib>

double random_gauss() {
    return sqrt(-2 * log(static_cast<double>(rand()) / RAND_MAX)) * cos(2 * M_PI * static_cast<double>(rand()) / RAND_MAX);
}

void simulate_option_pricing() {
    while (true) {
        double S0 = 100, K = 100, T = 1, r = 0.05, sigma = 0.2;
        double dt = T / 365;
        double S = S0;
        for (int i = 0; i < 365; ++i) {
            double z = random_gauss();
            S *= 1 + r * dt + sigma * z * sqrt(dt);
        }
        double payoff = std::max(S - K, 0.0);
        std::cout << payoff << std::endl;
    }
}

int main() {
    simulate_option_pricing();
    return 0;
}