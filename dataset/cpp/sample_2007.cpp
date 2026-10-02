#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class FinancialModel {
public:
    FinancialModel(double S0, double K, double T, double r, double sigma)
        : S0(S0), K(K), T(T), r(r), sigma(sigma) {}

    std::vector<std::vector<double>> simulate_paths(int num_simulations, int num_steps) {
        std::vector<std::vector<double>> paths;
        double dt = T / num_steps;
        for (int i = 0; i < num_simulations; ++i) {
            double S = S0;
            std::vector<double> path = {S};
            for (int j = 0; j < num_steps; ++j) {
                double dS = S * (r * dt + sigma * std::sqrt(dt) * random_gauss());
                S += dS;
                path.push_back(S);
            }
            paths.push_back(path);
        }
        return paths;
    }

private:
    double random_gauss() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::normal_distribution<> dis(0, 1);
        return dis(gen);
    }

    double S0, K, T, r, sigma;
};

class OptionPricer {
public:
    OptionPricer(FinancialModel& model) : model(model) {}

    double european_call_price(const std::vector<std::vector<double>>& paths) {
        double payoff = 0.0;
        for (const auto& path : paths) {
            payoff += std::max(path.back() - model.K, 0.0);
        }
        payoff /= paths.size();
        double discount_factor = std::exp(-model.r * model.T);
        return payoff * discount_factor;
    }

private:
    FinancialModel& model;
};

class AnalysisEngine {
public:
    AnalysisEngine(OptionPricer& pricer) : pricer(pricer) {}

    double execute(int num_simulations, int num_steps) {
        auto paths = pricer.model.simulate_paths(num_simulations, num_steps);
        double price = pricer.european_call_price(paths);
        return price;
    }

private:
    OptionPricer& pricer;
};

int main() {
    double S0 = 100.0;
    double K = 100.0;
    double T = 1.0;
    double r = 0.05;
    double sigma = 0.2;
    int num_simulations = 1000;
    int num_steps = 100;
    FinancialModel model(S0, K, T, r, sigma);
    OptionPricer pricer(model);
    AnalysisEngine engine(pricer);
    double price = engine.execute(num_simulations, num_steps);
    std::cout << "European Call Option Price: " << price << std::endl;
    return 0;
}