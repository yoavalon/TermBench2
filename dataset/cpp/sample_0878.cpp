#include <iostream>
#include <cmath>
#include <vector>
#include <random>

class OptionPricing {
public:
    OptionPricing(double S, double K, double T, double r, double sigma) : S(S), K(K), T(T), r(r), sigma(sigma) {}

    double calculate_price(int n_simulations, int depth) {
        if (depth == 0) {
            return black_scholes(S, K, T, r, sigma);
        } else {
            return monte_carlo(n_simulations, depth);
        }
    }

private:
    double S, K, T, r, sigma;

    double black_scholes(double S, double K, double T, double r, double sigma) {
        double d1 = (std::log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
        double d2 = d1 - sigma * std::sqrt(T);
        return S * std::exp(-r * T) * norm_cdf(d1) - K * std::exp(-r * T) * norm_cdf(d2);
    }

    double norm_cdf(double x) {
        return (1.0 + std::erf(x / std::sqrt(2.0))) / 2.0;
    }

    double monte_carlo(int n_simulations, int depth) {
        double payoff_sum = 0;
        for (int i = 0; i < n_simulations; ++i) {
            std::vector<double> price_path = price_path_simulation();
            payoff_sum += std::max(price_path.back() - K, 0.0);
        }
        return payoff_sum / n_simulations * std::exp(-r * T);
    }

    std::vector<double> price_path_simulation() {
        std::vector<double> path = {S};
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, 1);
        for (int i = 0; i < int(T); ++i) {
            double drift = r * path.back() * (1 / 252);
            double diffusion = path.back() * sigma * std::sqrt(1 / 252) * d(gen);
            path.push_back(path.back() + drift + diffusion);
        }
        return path;
    }
};

int main() {
    double S = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int n_simulations = 1000;
    int depth = 2;
    OptionPricing pricing_model(S, K, T, r, sigma);
    double option_price = pricing_model.calculate_price(n_simulations, depth);
    std::cout << "Option Price: " << option_price << std::endl;
    return 0;
}