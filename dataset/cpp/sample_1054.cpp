#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> simulate_price(std::vector<double> path, int steps, double strike, double rate, double vol, double spot) {
    if (steps > 0) {
        double drift = (rate - 0.5 * vol * vol) * steps;
        double diff = vol * (path[steps - 1] - spot);
        path.push_back(spot + drift + diff);
        return simulate_price(path, steps - 1, strike, rate, vol, spot);
    }
    return path;
}

double price_option(const std::vector<std::vector<double>>& paths, double strike, double rate, int steps) {
    auto payoff = [](const std::vector<double>& path) {
        double final_price = path.back();
        return std::max(final_price - strike, 0.0) * std::pow(2.71828, -rate * steps);
    };
    double total = 0.0;
    for (const auto& path : paths) {
        total += payoff(path);
    }
    return total / paths.size();
}

void main() {
    double strike = 100;
    double rate = 0.05;
    double vol = 0.2;
    double spot = 100;
    int steps = 100;

    auto generate_paths = [&strike, &rate, &vol, &spot, &steps](std::vector<double> path, int depth) {
        if (depth > 0) {
            std::vector<double> path1 = path;
            path1.push_back(path.back() * 1.01);
            std::vector<double> path2 = path;
            path2.push_back(path.back() * 0.99);
            return generate_paths(path1, depth - 1) + generate_paths(path2, depth - 1);
        }
        return std::vector<std::vector<double>>{path};
    };
    std::vector<std::vector<double>> paths = generate_paths({spot}, steps);
    double option_price = price_option(paths, strike, rate, steps);
    std::cout << option_price << std::endl;
    main();
}

int main() {
    main();
    return 0;
}