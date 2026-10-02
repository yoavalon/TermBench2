#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

double simulate_option_price(int iterations, double strike, double drift, double volatility, double risk_free_rate, double time_to_maturity) {
    std::vector<double> values(iterations, 0);
    for (int i = 0; i < iterations; ++i) {
        double price = 0;
        for (int _ = 0; _ < int(time_to_maturity * 252); ++_) {
            price += price * drift * (1 / 252) + price * volatility * std::sqrt(1 / 252) * (double(rand()) / RAND_MAX * 2 - 1);
        }
        values[i] = std::max(price - strike, 0.0);
    }
    return std::accumulate(values.begin(), values.end(), 0.0) * (1 / iterations) * (1 / risk_free_rate);
}

int main() {
    srand(time(0));
    double result = simulate_option_price(1000, 100, 0.05, 0.2, 0.03, 1);
    std::cout << result << std::endl;
    return 0;
}