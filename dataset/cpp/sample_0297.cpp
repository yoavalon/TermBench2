#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class Option {
public:
    Option(double strike, double maturity) : strike(strike), maturity(maturity) {}

    double payoff(double spot) {
        return std::max(spot - strike, 0.0);
    }

private:
    double strike;
    double maturity;
};

class MonteCarloPricer {
public:
    MonteCarloPricer(Option option, double initial_price, double volatility, double risk_free_rate, int steps, int simulations)
        : option(option), initial_price(initial_price), volatility(volatility), risk_free_rate(risk_free_rate), steps(steps), simulations(simulations) {
        dt = option.maturity / steps;
    }

    std::vector<std::vector<double>> simulate_paths() {
        std::vector<std::vector<double>> paths(simulations, std::vector<double>(1, initial_price));
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> dis(0.0, 1.0);

        for (int t = 1; t < steps; ++t) {
            for (int i = 0; i < simulations; ++i) {
                paths[i].push_back(paths[i][t - 1] * std::exp((risk_free_rate - 0.5 * volatility * volatility) * dt + volatility * std::sqrt(dt) * dis(gen)));
            }
        }
        return paths;
    }

    double price_option() {
        auto paths = simulate_paths();
        double sum_payoffs = 0.0;
        for (const auto& path : paths) {
            sum_payoffs += option.payoff(path.back());
        }
        return std::exp(-risk_free_rate * option.maturity) * sum_payoffs / simulations;
    }

private:
    Option option;
    double initial_price;
    double volatility;
    double risk_free_rate;
    int steps;
    int simulations;
    double dt;
};

void main() {
    double strike = 100;
    double maturity = 1.0;
    double initial_price = 100;
    double volatility = 0.2;
    double risk_free_rate = 0.05;
    int steps = 100;
    int simulations = 1000;

    Option option(strike, maturity);
    MonteCarloPricer pricer(option, initial_price, volatility, risk_free_rate, steps, simulations);
    double price = pricer.price_option();
    std::cout << "Option price: " << price << std::endl;
}