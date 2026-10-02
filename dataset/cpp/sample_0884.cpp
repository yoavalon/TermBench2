#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class OptionPricer {
public:
    OptionPricer(double strike, double spot, double vol, double rate, double div, double T)
        : strike(strike), spot(spot), vol(vol), rate(rate), div(div), T(T) {}

    double d1(double S, double K, double T, double r, double q, double sigma) {
        return (log(S / K) + (r - q + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    }

    double d2(double d1, double sigma, double T) {
        return d1 - sigma * sqrt(T);
    }

    double call_price(double S, double K, double T, double r, double q, double sigma) {
        if (T <= 0) {
            return std::max(0.0, S - K);
        }
        double d1_val = d1(S, K, T, r, q, sigma);
        double d2_val = d2(d1_val, sigma, T);
        return S * exp(-q * T) * normcdf(d1_val) - K * exp(-r * T) * normcdf(d2_val);
    }

private:
    double strike, spot, vol, rate, div, T;
};

double normcdf(double x) {
    // Approximation of the cumulative distribution function for a standard normal distribution
    return 0.5 * erfc(-x * M_SQRT1_2);
}

class MonteCarloSimulator {
public:
    MonteCarloSimulator(OptionPricer& pricer, int paths, int steps)
        : pricer(pricer), paths(paths), steps(steps) {}

    std::vector<double> simulate() {
        std::vector<double> prices;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, 1);
        for (int i = 0; i < paths; ++i) {
            double price_path = pricer.spot;
            for (int j = 1; j < steps; ++j) {
                price_path = _step(price_path, gen, d);
            }
            prices.push_back(price_path);
        }
        return prices;
    }

private:
    double _step(double S, std::mt19937& gen, std::normal_distribution<>& d) {
        double dt = pricer.T / steps;
        double dS = S * (pricer.rate - pricer.div) * dt + S * pricer.vol * sqrt(dt) * d(gen);
        return S + dS;
    }

    OptionPricer& pricer;
    int paths, steps;
};

void main() {
    double strike = 100;
    double spot = 100;
    double vol = 0.2;
    double rate = 0.05;
    double div = 0.02;
    double T = 1;
    int paths = 1000;
    int steps = 100;
    OptionPricer pricer(strike, spot, vol, rate, div, T);
    MonteCarloSimulator simulator(pricer, paths, steps);
    std::vector<double> final_prices = simulator.simulate();
    double option_value = 0;
    for (double price : final_prices) {
        option_value += pricer.call_price(price, strike, T, rate, div, vol);
    }
    option_value /= paths;
    std::cout << option_value << std::endl;
}

int main() {
    main();
    return 0;
}