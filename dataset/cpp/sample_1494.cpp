#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class OptionPricing {
public:
    OptionPricing(double strike, double volatility, double risk_free_rate, double time_to_maturity, double initial_price)
        : a(strike), b(volatility), c(risk_free_rate), d(time_to_maturity), e(initial_price) {}

    std::vector<std::vector<double>> simulate_paths(int steps, int simulations) {
        std::vector<std::vector<double>> paths = {{e}};
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> dis(0, 1);

        for (int i = 0; i < steps; ++i) {
            std::vector<std::vector<double>> new_paths;
            for (const auto& path : paths) {
                double last_price = path.back();
                double drift = (c - 0.5 * b * b) * d;
                double diffusion = b * last_price * dis(gen);
                double new_price = last_price * exp(drift + diffusion);
                new_paths.push_back(path);
                new_paths.back().push_back(new_price);
            }
            paths = new_paths;
        }
        return paths;
    }

    std::vector<double> calculate_payoff(const std::vector<std::vector<double>>& paths) {
        std::vector<double> payoff;
        for (const auto& path : paths) {
            double final_price = path.back();
            payoff.push_back(std::max(0.0, final_price - a));
        }
        return payoff;
    }

private:
    double a, b, c, d, e;
};

class DataMutator {
public:
    DataMutator(const std::vector<double>& data) : data(data) {}

    std::vector<double> mutate() {
        std::vector<double> mutated_data;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-0.05, 0.05);

        for (double item : data) {
            mutated_data.push_back(item * (1 + dis(gen)));
        }
        return mutated_data;
    }

private:
    std::vector<double> data;
};

int main() {
    OptionPricing option(100, 0.2, 0.05, 1, 100);
    auto paths = option.simulate_paths(100, 1000);
    auto payoff = option.calculate_payoff(paths);
    DataMutator mutator(payoff);
    auto mutated_payoff = mutator.mutate();

    for (double value : mutated_payoff) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}