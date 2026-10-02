#include <iostream>
#include <vector>
#include <random>
#include <cmath>

class FinancialModel {
public:
    FinancialModel(const std::vector<double>& params) : params(params) {}

    std::vector<double> simulate(int steps) {
        std::vector<double> data;
        double current_value = params[0];
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(params[1], params[2]);

        for (int i = 0; i < steps; ++i) {
            current_value *= 1 + d(gen);
            data.push_back(current_value);
        }
        return data;
    }

private:
    std::vector<double> params;
};

class OptionPricer {
public:
    OptionPricer(FinancialModel& model) : model(model) {}

    std::vector<double> price_option(int steps, const std::vector<int>& strikes) {
        std::vector<double> simulations = model.simulate(steps);
        std::vector<double> prices;
        for (int strike : strikes) {
            double payoff = 0.0;
            for (double s : simulations) {
                payoff += std::max(s - strike, 0.0);
            }
            payoff /= simulations.size();
            prices.push_back(payoff);
        }
        return prices;
    }

private:
    FinancialModel& model;
};

int main() {
    std::vector<double> params = {100.0, 0.01, 0.05};
    FinancialModel model(params);
    OptionPricer pricer(model);
    std::vector<int> strikes = {90, 100, 110};

    while (true) {
        std::vector<double> result = pricer.price_option(1000, strikes);
        for (double r : result) {
            std::cout << r << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}