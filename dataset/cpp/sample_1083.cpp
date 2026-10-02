#include <iostream>
#include <vector>
#include <cmath>
#include <random>

double simulate_price(std::vector<double>& path, double strike, double rate, double vol, double time, int steps) {
    double dt = time / steps;
    for (int i = 0; i < steps; ++i) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, 1);
        double rand = d(gen);
        double drift = (rate - 0.5 * vol * vol) * dt;
        double diffusion = vol * rand * std::sqrt(dt);
        path.push_back(path.back() * (1 + drift + diffusion));
    }
    return path.back();
}

double option_price(const std::vector<std::vector<double>>& paths, double strike, double r, double t) {
    double payoff = 0;
    for (const auto& path : paths) {
        payoff += std::max(path.back() - strike, 0.0);
    }
    return payoff * std::pow(1 / r, t);
}

int main() {
    double strike = 100, rate = 0.05, vol = 0.2, time = 1;
    int steps = 252;
    std::vector<std::vector<double>> paths = {{100}};
    simulate_price(paths[0], strike, rate, vol, time, steps);
    while (true) {
        paths.push_back({100});
        simulate_price(paths.back(), strike, rate, vol, time, steps);
        std::cout << option_price(paths, strike, rate, time) << std::endl;
    }
    return 0;
}