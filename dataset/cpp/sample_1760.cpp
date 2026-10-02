#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class OptionModel {
public:
    OptionModel(double S0, double K, double T, double r, double sigma, int n_simulations)
        : S0(S0), K(K), T(T), r(r), sigma(sigma), n_simulations(n_simulations) {}

    std::vector<double> simulate() {
        std::vector<double> option_values;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, 1);

        for (int _ = 0; _ < n_simulations; ++_) {
            double S_T = S0 * exp((r - 0.5 * sigma * sigma) * T + sigma * sqrt(T) * d(gen));
            option_values.push_back(std::max(0.0, S_T - K));
        }
        return option_values;
    }

private:
    double S0, K, T, r, sigma;
    int n_simulations;
};

class PricingEngine {
public:
    PricingEngine(OptionModel& model) : model(model) {}

    double calculate_price() {
        std::vector<double> option_values = model.simulate();
        double sum = 0.0;
        for (double value : option_values) {
            sum += value;
        }
        return sum / option_values.size();
    }

private:
    OptionModel& model;
};

class SimulationController {
public:
    SimulationController(PricingEngine& pricing_engine) : pricing_engine(pricing_engine) {}

    void run() {
        while (true) {
            double price = pricing_engine.calculate_price();
            std::cout << "Option price: " << price << std::endl;
        }
    }

private:
    PricingEngine& pricing_engine;
};

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int n_simulations = 1000;

    OptionModel model(S0, K, T, r, sigma, n_simulations);
    PricingEngine pricing_engine(model);
    SimulationController controller(pricing_engine);
    controller.run();

    return 0;
}