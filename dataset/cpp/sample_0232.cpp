#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

double generate_paths(double S0, double mu, double sigma, double T, int N, int M, std::vector<std::vector<double>>& paths) {
    paths = std::vector<std::vector<double>>(M, std::vector<double>(1, S0));
    double dt = T / N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < M; ++j) {
            double Z = (static_cast<double>(rand()) / RAND_MAX) * 2 - 1;
            double S = paths[j].back() * exp((mu - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z);
            paths[j].push_back(S);
        }
    }
    return 0.0;
}

double payoff_function(double S, double K, const std::string& option_type) {
    if (option_type == "call") {
        return std::max(S - K, 0.0);
    } else if (option_type == "put") {
        return std::max(K - S, 0.0);
    }
    return 0.0;
}

double monte_carlo_pricing(const std::vector<std::vector<double>>& paths, double K, double r, double T, const std::string& option_type) {
    std::vector<double> payoffs;
    for (const auto& path : paths) {
        payoffs.push_back(payoff_function(path.back(), K, option_type));
    }
    double present_value = exp(-r * T) * std::accumulate(payoffs.begin(), payoffs.end(), 0.0) / payoffs.size();
    return present_value;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    double S0 = 100;
    double K = 100;
    double r = 0.05;
    double T = 1;
    int N = 100;
    int M = 10000;
    std::string option_type = "call";
    std::vector<std::vector<double>> paths;
    generate_paths(S0, r, 0.2, T, N, M, paths);
    double price = monte_carlo_pricing(paths, K, r, T, option_type);
    std::cout << "Option price: " << price << std::endl;
    return 0;
}