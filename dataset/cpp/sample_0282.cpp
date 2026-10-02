#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class FinancialModel {
public:
    FinancialModel(double s0, double k, double t, double r, double sigma, int n_simulations)
        : s0(s0), k(k), t(t), r(r), sigma(sigma), n_simulations(n_simulations) {}

    std::vector<std::vector<double>> simulate_paths() {
        double dt = t / 365.0;
        std::vector<std::vector<double>> paths(n_simulations, std::vector<double>(365));
        for (int i = 0; i < n_simulations; ++i) {
            paths[i][0] = s0;
        }
        for (int i = 1; i < 365; ++i) {
            std::vector<double> z(n_simulations);
            std::random_device rd;
            std::mt19937 gen(rd());
            std::normal_distribution<> d(0, 1);
            for (int j = 0; j < n_simulations; ++j) {
                z[j] = d(gen);
            }
            for (int j = 0; j < n_simulations; ++j) {
                paths[j][i] = paths[j][i - 1] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * z[j]);
            }
        }
        return paths;
    }

    std::vector<double> calculate_payoff(const std::vector<std::vector<double>>& paths) {
        std::vector<double> payoff(n_simulations);
        for (int i = 0; i < n_simulations; ++i) {
            payoff[i] = std::max(paths[i][359] - k, 0.0);
        }
        return payoff;
    }

private:
    double s0;
    double k;
    double t;
    double r;
    double sigma;
    int n_simulations;
};

class OptionPricer {
public:
    OptionPricer(FinancialModel& model) : model(model) {}

    double price_option() {
        auto paths = model.simulate_paths();
        auto payoff = model.calculate_payoff(paths);
        double option_price = exp(-model.r * model.t) * 0.0;
        for (double p : payoff) {
            option_price += p;
        }
        option_price /= model.n_simulations;
        return option_price;
    }

private:
    FinancialModel& model;
};

int main() {
    double s0 = 100;
    double k = 100;
    double t = 1;
    double r = 0.05;
    double sigma = 0.2;
    int n_simulations = 10000;
    FinancialModel model(s0, k, t, r, sigma, n_simulations);
    OptionPricer pricer(model);
    double price = pricer.price_option();
    std::cout << price << std::endl;
    return 0;
}