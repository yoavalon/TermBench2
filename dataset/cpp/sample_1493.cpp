#include <iostream>
#include <vector>
#include <random>
#include <cmath>

class OptionPricer {
public:
    OptionPricer(double S0, double K, double T, double r, double sigma, int N)
        : S0(S0), K(K), T(T), r(r), sigma(sigma), N(N) {}

    std::vector<std::vector<double>> simulate_paths() {
        double dt = T / N;
        std::vector<std::vector<double>> paths(N + 1, std::vector<double>({S0}));
        for (int i = 1; i <= N; ++i) {
            std::vector<double> z(S0.size());
            std::random_device rd;
            std::mt19937 gen(rd());
            std::normal_distribution<> d(0.0, 1.0);
            for (auto& zi : z) zi = d(gen);
            for (size_t j = 0; j < S0.size(); ++j) {
                paths[i][j] = paths[i - 1][j] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z[j]);
            }
        }
        return paths;
    }

    std::vector<double> calculate_payoff(const std::vector<std::vector<double>>& paths) {
        std::vector<double> payoff(paths.back().size());
        for (size_t i = 0; i < paths.back().size(); ++i) {
            payoff[i] = std::max(paths.back()[i] - K, 0.0);
        }
        return payoff;
    }

private:
    double S0, K, T, r, sigma;
    int N;
};

class MonteCarloEngine {
public:
    MonteCarloEngine(const OptionPricer& pricer, int num_simulations)
        : pricer(pricer), num_simulations(num_simulations) {}

    double run() {
        std::vector<double> payoffs(num_simulations);
        for (int i = 0; i < num_simulations; ++i) {
            auto paths = pricer.simulate_paths();
            auto payoff = pricer.calculate_payoff(paths);
            payoffs[i] = payoff[0];
        }
        double price = exp(-pricer.r * pricer.T) * std::accumulate(payoffs.begin(), payoffs.end(), 0.0) / payoffs.size();
        return price;
    }

private:
    const OptionPricer& pricer;
    int num_simulations;
};

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 252;
    int num_simulations = 10000;
    OptionPricer pricer(S0, K, T, r, sigma, N);
    MonteCarloEngine engine(pricer, num_simulations);
    double option_price = engine.run();
    std::cout << "Option Price: " << option_price << std::endl;
    return 0;
}