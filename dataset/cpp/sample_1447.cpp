#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<std::vector<double>> generate_paths(double s0, double mu, double sigma, double dt, double T, int N) {
    std::vector<std::vector<double>> paths(N, std::vector<double>(static_cast<int>(T / dt) + 1, 0.0));
    for (int i = 0; i < N; ++i) {
        paths[i][0] = s0;
    }
    for (int t = 1; t <= static_cast<int>(T / dt); ++t) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0.0, 1.0);
        for (int i = 0; i < N; ++i) {
            double z = d(gen);
            paths[i][t] = paths[i][t - 1] * exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z);
        }
    }
    return paths;
}

std::vector<double> calculate_payoff(const std::vector<std::vector<double>>& paths, double strike, const std::string& option_type) {
    std::vector<double> payoff(paths.size(), 0.0);
    if (option_type == "call") {
        for (size_t i = 0; i < paths.size(); ++i) {
            payoff[i] = std::max(paths[i].back() - strike, 0.0);
        }
    } else if (option_type == "put") {
        for (size_t i = 0; i < paths.size(); ++i) {
            payoff[i] = std::max(strike - paths[i].back(), 0.0);
        }
    }
    return payoff;
}

double monte_carlo_pricing(double s0, double strike, double r, double T, double sigma, int N, double dt, const std::string& option_type) {
    auto paths = generate_paths(s0, r, sigma, dt, T, N);
    auto payoff = calculate_payoff(paths, strike, option_type);
    double discount_factor = exp(-r * T);
    double option_price = 0.0;
    for (double p : payoff) {
        option_price += p;
    }
    option_price *= discount_factor / N;
    return option_price;
}

int main() {
    double s0 = 100.0;
    double strike = 100.0;
    double r = 0.05;
    double T = 1.0;
    double sigma = 0.2;
    int N = 10000;
    double dt = 0.01;
    std::string option_type = "call";
    double price = monte_carlo_pricing(s0, strike, r, T, sigma, N, dt, option_type);
    std::cout << price << std::endl;
    return 0;
}