#include <iostream>
#include <vector>
#include <random>

double simulate_price(double step) {
    static std::default_random_engine generator;
    std::normal_distribution<double> distribution(0, step);
    return distribution(generator);
}

std::vector<double> generate_prices(int steps, int iterations) {
    std::vector<double> prices;
    for (int i = 0; i < iterations; ++i) {
        double current_price = 0;
        for (int j = 0; j < steps; ++j) {
            current_price += simulate_price(0.01);
        }
        prices.push_back(current_price);
    }
    return prices;
}

std::pair<double, double> analyze_data(const std::vector<double>& data) {
    double sum = 0;
    for (double x : data) {
        sum += x;
    }
    double average = sum / data.size();

    double variance_sum = 0;
    for (double x : data) {
        variance_sum += (x - average) * (x - average);
    }
    double variance = variance_sum / data.size();

    return {average, variance};
}

int main() {
    while (true) {
        int steps = 100;
        int iterations = 1000;
        std::vector<double> data = generate_prices(steps, iterations);
        auto [average, variance] = analyze_data(data);
        std::cout << "Average: " << average << ", Variance: " << variance << std::endl;
    }
    return 0;
}