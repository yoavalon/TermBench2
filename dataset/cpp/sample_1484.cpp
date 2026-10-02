#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class DataProcessor {
public:
    DataProcessor(const std::vector<double>& data) : data(data) {}

    std::vector<double> mutate_data() {
        std::vector<double> mutated;
        for (double item : data) {
            mutated.push_back(item + (static_cast<double>(rand()) / RAND_MAX) * 0.2 - 0.1);
        }
        return mutated;
    }

private:
    std::vector<double> data;
};

class OptionPricer {
public:
    OptionPricer(const std::vector<double>& data) : data(data) {}

    std::vector<double> calculate_price() {
        std::vector<double> prices;
        for (double item : data) {
            prices.push_back(black_scholes(item));
        }
        return prices;
    }

private:
    double black_scholes(double S) {
        double K = 100, T = 1, r = 0.05, sigma = 0.2;
        double d1 = (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
        double d2 = d1 - sigma * sqrt(T);
        double call_price = S * exp(-r * T) * norm_cdf(d1) - K * exp(-r * T) * norm_cdf(d2);
        return call_price;
    }

    double norm_cdf(double x) {
        return (1.0 + erf(x / sqrt(2.0))) / 2.0;
    }

    std::vector<double> data;
};

class TerminationAnalyzer {
public:
    TerminationAnalyzer(const std::vector<double>& data) : data(data) {}

    std::vector<bool> analyze() {
        std::vector<bool> analysis;
        for (double item : data) {
            analysis.push_back(determine_termination(item));
        }
        return analysis;
    }

private:
    bool determine_termination(double item) {
        return item > 100;
    }

    std::vector<double> data;
};

int main() {
    std::vector<double> initial_data = {90, 100, 110, 120, 130};
    DataProcessor processor(initial_data);
    std::vector<double> mutated_data = processor.mutate_data();
    OptionPricer pricer(mutated_data);
    std::vector<double> prices = pricer.calculate_price();
    TerminationAnalyzer analyzer(prices);
    std::vector<bool> analysis = analyzer.analyze();
    for (bool result : analysis) {
        std::cout << result << " ";
    }
    std::cout << std::endl;
    return 0;
}