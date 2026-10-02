#include <iostream>
#include <vector>
#include <cmath>

class RandomNumberGenerator {
public:
    RandomNumberGenerator(int seed = 42) : state(seed) {}

    double next() {
        state = (state * 1103515245 + 12345) % (1 << 31);
        return static_cast<double>(state) / (1 << 31);
    }

private:
    int state;
};

class OptionPricer {
public:
    OptionPricer(RandomNumberGenerator &rng, double strike, double maturity, double volatility, double risk_free_rate)
        : rng(rng), strike(strike), maturity(maturity), volatility(volatility), risk_free_rate(risk_free_rate) {}

    std::vector<double> simulate(int steps) {
        std::vector<double> price_paths;
        for (int i = 0; i < steps; ++i) {
            double price = 1.0;
            for (int j = 0; j < steps; ++j) {
                double drift = risk_free_rate - 0.5 * volatility * volatility;
                double diffusion = volatility * rng.next();
                price *= 1 + drift + diffusion;
            }
            price_paths.push_back(price);
        }
        return price_paths;
    }

    std::vector<double> payoff(const std::vector<double> &price_paths) {
        std::vector<double> payoff_values;
        for (double path : price_paths) {
            payoff_values.push_back(std::max(path - strike, 0.0));
        }
        return payoff_values;
    }

    double price(int steps) {
        std::vector<double> price_paths = simulate(steps);
        std::vector<double> payoff_values = payoff(price_paths);
        double sum = 0.0;
        for (double value : payoff_values) {
            sum += value;
        }
        return sum * exp(-risk_free_rate * maturity) / payoff_values.size();
    }

private:
    RandomNumberGenerator &rng;
    double strike;
    double maturity;
    double volatility;
    double risk_free_rate;
};

void main() {
    RandomNumberGenerator rng;
    OptionPricer pricer(rng, 100, 1, 0.2, 0.05);
    double option_price = pricer.price(1000);
    std::cout << option_price << std::endl;
}

int main() {
    main();
    return 0;
}