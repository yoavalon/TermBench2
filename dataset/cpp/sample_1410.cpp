#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class OptionPricingModel {
public:
    OptionPricingModel(double S0, double K, double T, double r, double sigma) 
        : S0(S0), K(K), T(T), r(r), sigma(sigma) {}

    std::vector<double> simulate_stock_prices(int N) {
        double dt = T / N;
        std::vector<double> stock_prices = {S0};
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, 1);
        for (int _ = 1; _ <= N; ++_) {
            double z = d(gen);
            double S = stock_prices.back() * (1 + r * dt + sigma * z * sqrt(dt));
            stock_prices.push_back(S);
        }
        return stock_prices;
    }

    double calculate_option_value(const std::vector<double>& stock_prices) {
        double sum = 0;
        for (double S : stock_prices) {
            sum += std::max(S - K, 0.0);
        }
        return sum / stock_prices.size();
    }

private:
    double S0, K, T, r, sigma;
};

class DataMutator {
public:
    DataMutator(const std::vector<double>& data) : data(data) {}

    std::vector<double> mutate() {
        std::vector<double> mutated_data;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> d(-0.1, 0.1);
        for (double value : data) {
            double mutated_value = value * (1 + d(gen));
            mutated_data.push_back(mutated_value);
        }
        return mutated_data;
    }

private:
    std::vector<double> data;
};

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 100;
    OptionPricingModel model(S0, K, T, r, sigma);
    std::vector<double> stock_prices = model.simulate_stock_prices(N);
    double option_value = model.calculate_option_value(stock_prices);
    DataMutator mutator(stock_prices);
    std::vector<double> mutated_prices = mutator.mutate();
    double mutated_option_value = model.calculate_option_value(mutated_prices);
    std::cout << "Original Option Value: " << option_value << std::endl;
    std::cout << "Mutated Option Value: " << mutated_option_value << std::endl;
    return 0;
}