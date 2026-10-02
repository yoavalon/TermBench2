#include <iostream>
#include <vector>
#include <cmath>

class RandomGenerator {
public:
    RandomGenerator(unsigned int seed) : seed(seed) {}

    double generate() {
        seed = (1664525 * seed + 1013904223) % 4294967296;
        return static_cast<double>(seed) / 4294967296;
    }

private:
    unsigned int seed;
};

class OptionPricer {
public:
    OptionPricer(RandomGenerator& random_gen, double S0, double K, double T, double r, double sigma, int N)
        : random_gen(random_gen), S0(S0), K(K), T(T), r(r), sigma(sigma), N(N) {}

    std::vector<std::vector<double>> simulate_paths() {
        std::vector<std::vector<double>> paths;
        double dt = T / N;
        for (int i = 0; i < 1000; ++i) {
            double S = S0;
            std::vector<double> path = {S};
            for (int j = 0; j < N; ++j) {
                double Z = random_gen.generate();
                S += S * r * dt + S * sigma * std::sqrt(dt) * (2 * Z - 1);
                path.push_back(S);
            }
            paths.push_back(path);
        }
        return paths;
    }

    double price() {
        std::vector<std::vector<double>> paths = simulate_paths();
        double payoff_sum = 0;
        for (const auto& path : paths) {
            double payoff = std::max(path.back() - K, 0.0);
            payoff_sum += payoff;
        }
        return std::exp(-r * T) * (payoff_sum / paths.size());
    }

private:
    RandomGenerator& random_gen;
    double S0, K, T, r, sigma;
    int N;
};

int main() {
    unsigned int seed = 12345;
    RandomGenerator random_gen(seed);
    OptionPricer pricer(random_gen, 100, 100, 1, 0.05, 0.2, 100);
    double option_price = pricer.price();
    std::cout << "Option Price: " << option_price << std::endl;
    return 0;
}