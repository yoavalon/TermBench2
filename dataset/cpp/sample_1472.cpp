#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class FinancialModel {
public:
    FinancialModel(double initial_price, double volatility, double risk_free_rate, int time_steps, int num_simulations)
        : a(initial_price), b(volatility), c(risk_free_rate), d(time_steps), e(num_simulations) {}

    std::vector<std::vector<double>> generate_paths() {
        std::vector<std::vector<double>> paths;
        paths.reserve(e);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, 1);

        for (int i = 0; i < e; ++i) {
            std::vector<double> path;
            path.reserve(d + 1);
            path.push_back(a);
            for (int j = 0; j < d; ++j) {
                double z = d(gen);
                double next_price = path.back() * exp(c - 0.5 * b * b + b * z);
                path.push_back(next_price);
            }
            paths.push_back(path);
        }
        return paths;
    }

private:
    double a;
    double b;
    double c;
    int d;
    int e;
};

class OptionPricer {
public:
    OptionPricer(FinancialModel& model, double strike_price, std::string option_type = "call")
        : f(model), g(strike_price), h(option_type) {}

    double price_option() {
        std::vector<std::vector<double>> paths = f.generate_paths();
        std::vector<double> payoffs;
        payoffs.reserve(paths.size());

        for (const auto& path : paths) {
            double payoff;
            if (h == "call") {
                payoff = std::max(path.back() - g, 0.0);
            } else {
                payoff = std::max(g - path.back(), 0.0);
            }
            payoffs.push_back(payoff);
        }
        return std::accumulate(payoffs.begin(), payoffs.end(), 0.0) / f.e;
    }

private:
    FinancialModel& f;
    double g;
    std::string h;
};

int main() {
    FinancialModel model(100, 0.2, 0.05, 100, 10000);
    OptionPricer pricer(model, 100, "call");
    double option_price = pricer.price_option();
    std::cout << "Option Price: " << option_price << std::endl;
    return 0;
}