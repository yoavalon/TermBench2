#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class OptionPricer {
public:
    OptionPricer(double S, double K, double T, double r, double sigma)
        : S(S), K(K), T(T), r(r), sigma(sigma) {}

    std::vector<std::vector<double>> simulate_paths(int num_simulations, int num_steps) {
        std::vector<std::vector<double>> paths;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, 1);

        for (int i = 0; i < num_simulations; ++i) {
            std::vector<double> path = {S};
            for (int j = 0; j < num_steps - 1; ++j) {
                double delta_t = T / num_steps;
                double drift = (r - 0.5 * sigma * sigma) * delta_t;
                double diffusion = sigma * d(gen) * std::sqrt(delta_t);
                double next_price = path.back() * (1 + drift + diffusion);
                path.push_back(next_price);
            }
            paths.push_back(path);
        }
        return paths;
    }

    std::vector<double> calculate_payoff(const std::vector<std::vector<double>>& paths) {
        std::vector<double> payoffs;
        for (const auto& path : paths) {
            double payoff = std::max(path.back() - K, 0.0);
            payoffs.push_back(payoff);
        }
        return payoffs;
    }

    double price_option(int num_simulations, int num_steps) {
        std::vector<std::vector<double>> paths = simulate_paths(num_simulations, num_steps);
        std::vector<double> payoffs = calculate_payoff(paths);
        double option_price = std::accumulate(payoffs.begin(), payoffs.end(), 0.0) / num_simulations * (1 / r);
        return option_price;
    }

private:
    double S, K, T, r, sigma;
};

void recursive_pricer(OptionPricer& pricer, int num_simulations, int num_steps) {
    double current_price = pricer.price_option(num_simulations, num_steps);
    std::cout << "Current option price: " << current_price << std::endl;
    recursive_pricer(pricer, num_simulations, num_steps);
}

int main() {
    double S = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    OptionPricer pricer(S, K, T, r, sigma);
    recursive_pricer(pricer, 1000, 100);
    return 0;
}