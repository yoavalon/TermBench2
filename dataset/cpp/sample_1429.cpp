#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class DataMutation {
public:
    DataMutation(const std::vector<double>& data) : data(data) {}

    std::vector<double> apply_mutation(const std::function<std::vector<double>(const std::vector<double>&)>& mutation_function) {
        data = mutation_function(data);
        return data;
    }

private:
    std::vector<double> data;
};

class FinancialModel {
public:
    FinancialModel(double initial_price, double volatility, double risk_free_rate, int time_steps, int simulations)
        : initial_price(initial_price), volatility(volatility), risk_free_rate(risk_free_rate), time_steps(time_steps), simulations(simulations) {}

    std::vector<std::vector<double>> simulate_paths() {
        double dt = 1.0 / time_steps;
        double drift = (risk_free_rate - 0.5 * volatility * volatility) * dt;
        double diffusion = volatility * std::sqrt(dt);
        std::vector<std::vector<double>> paths(time_steps + 1, std::vector<double>(simulations));
        paths[0] = std::vector<double>(simulations, initial_price);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0.0, 1.0);

        for (int t = 1; t <= time_steps; ++t) {
            for (int i = 0; i < simulations; ++i) {
                double rand = d(gen);
                paths[t][i] = paths[t - 1][i] * std::exp(drift + diffusion * rand);
            }
        }
        return paths;
    }

    std::vector<double> calculate_payoff(double strike_price, const std::string& option_type = "call") {
        std::vector<std::vector<double>> paths = simulate_paths();
        std::vector<double> payoff(simulations);
        if (option_type == "call") {
            for (int i = 0; i < simulations; ++i) {
                payoff[i] = std::max(paths[time_steps][i] - strike_price, 0.0);
            }
        } else if (option_type == "put") {
            for (int i = 0; i < simulations; ++i) {
                payoff[i] = std::max(strike_price - paths[time_steps][i], 0.0);
            }
        }
        return payoff;
    }

    double price_option(double strike_price, const std::string& option_type = "call") {
        std::vector<double> payoff = calculate_payoff(strike_price, option_type);
        double option_price = std::exp(-risk_free_rate * time_steps) * std::accumulate(payoff.begin(), payoff.end(), 0.0) / payoff.size();
        return option_price;
    }

private:
    double initial_price;
    double volatility;
    double risk_free_rate;
    int time_steps;
    int simulations;
};

void main() {
    std::vector<double> data(100);
    for (auto& d : data) {
        d = static_cast<double>(rand()) / RAND_MAX;
    }
    DataMutation data_mutator(data);
    auto mutated_data = data_mutator.apply_mutation([](const std::vector<double>& x) {
        std::vector<double> result(x.size());
        for (size_t i = 0; i < x.size(); ++i) {
            result[i] = x[i] * 2;
        }
        return result;
    });
    FinancialModel financial_model(mutated_data[0], 0.2, 0.05, 252, 10000);
    double option_price = financial_model.price_option(100, "call");
    std::cout << option_price << std::endl;
}