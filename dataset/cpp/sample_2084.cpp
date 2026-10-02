#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class FinancialModel {
public:
    FinancialModel(double S0, double K, double T, double r, double sigma, int N) 
        : S0(S0), K(K), T(T), r(r), sigma(sigma), N(N) {}

    std::vector<std::vector<double>> simulate_paths() {
        double dt = T / N;
        std::vector<std::vector<double>> S(N, std::vector<double>(N));
        S[0] = S0;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0.0, 1.0);
        for (int t = 1; t < N; ++t) {
            for (int i = 0; i < N; ++i) {
                double Z = d(gen);
                S[t][i] = S[t - 1][i] * exp((r - 0.5 * sigma * sigma) * dt + sigma * sqrt(dt) * Z);
            }
        }
        return S;
    }

private:
    double S0, K, T, r, sigma;
    int N;
};

class OptionPricer {
public:
    OptionPricer(FinancialModel& model) : model(model) {}

    double european_call() {
        std::vector<std::vector<double>> S = model.simulate_paths();
        double payoff = 0.0;
        for (int i = 0; i < model.N; ++i) {
            payoff += std::max(S.back()[i] - model.K, 0.0);
        }
        double option_price = exp(-model.r * model.T) * payoff / model.N;
        return option_price;
    }

    double european_put() {
        std::vector<std::vector<double>> S = model.simulate_paths();
        double payoff = 0.0;
        for (int i = 0; i < model.N; ++i) {
            payoff += std::max(model.K - S.back()[i], 0.0);
        }
        double option_price = exp(-model.r * model.T) * payoff / model.N;
        return option_price;
    }

private:
    FinancialModel& model;
};

int main() {
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 1000;
    FinancialModel model(S0, K, T, r, sigma, N);
    OptionPricer pricer(model);
    double call_price = pricer.european_call();
    double put_price = pricer.european_put();
    std::cout << "European Call Price: " << call_price << std::endl;
    std::cout << "European Put Price: " << put_price << std::endl;
    return 0;
}