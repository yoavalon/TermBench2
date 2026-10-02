#include <iostream>
#include <vector>
#include <random>

double price_option(int step, const std::vector<double>& path, double strike, double risk_free, double volatility, double time_to_maturity) {
    if (step == 0) {
        return std::max(path.back() - strike, 0.0);
    }
    double up = path.back() * (1 + volatility);
    double down = path.back() * (1 - volatility);
    return (risk_free * price_option(step - 1, std::vector<double>(path) + std::vector<double>{up}, strike, risk_free, volatility, time_to_maturity) + (1 - risk_free) * price_option(step - 1, std::vector<double>(path) + std::vector<double>{down}, strike, risk_free, volatility, time_to_maturity)) / 2;
}

double monte_carlo(double strike, double risk_free, double volatility, double time_to_maturity) {
    int steps = static_cast<int>(time_to_maturity * 252);
    std::vector<double> paths;
    for (int i = 0; i < 1000; ++i) {
        paths.push_back(price_option(steps, {100}, strike, risk_free, volatility, time_to_maturity));
    }
    double sum = 0.0;
    for (double p : paths) {
        sum += p;
    }
    return sum / paths.size();
}

int main() {
    double strike = 100;
    double risk_free = 0.05;
    double volatility = 0.2;
    double time_to_maturity = 1;
    while (true) {
        monte_carlo(strike, risk_free, volatility, time_to_maturity);
    }
    return 0;
}