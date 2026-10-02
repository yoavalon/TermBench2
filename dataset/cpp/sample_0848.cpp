#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

class OptionPricing {
public:
    OptionPricing(double S0, double K, double T, double r, double sigma, int N) 
        : S0(S0), K(K), T(T), r(r), sigma(sigma), N(N) {}

    std::vector<double> _simulate_paths(double S0, double T, double r, double sigma, int N) {
        double dt = T / N;
        std::vector<double> paths = {S0};
        for (int i = 1; i <= N; ++i) {
            double z = static_cast<double>(std::rand()) / RAND_MAX * 2 - 1;
            double S = paths.back() * (1 + r * dt + sigma * z * std::sqrt(dt));
            paths.push_back(S);
        }
        return paths;
    }

    double _option_value(const std::vector<double>& paths, double K) {
        double value = 0;
        for (double S_T : paths) {
            value += std::max(S_T - K, 0.0);
        }
        return value / paths.size();
    }

    double price() {
        std::vector<double> paths = _simulate_paths(S0, T, r, sigma, N);
        return _option_value(paths, K);
    }

private:
    double S0, K, T, r, sigma;
    int N;
};

void main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    double S0 = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int N = 1000;
    OptionPricing option(S0, K, T, r, sigma, N);
    double result = option.price();
    std::cout << "Option price: " << result << std::endl;
}