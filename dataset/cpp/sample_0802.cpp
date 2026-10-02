#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class MonteCarlo {
public:
    MonteCarlo(double price, double strike, double rate, double volatility, double time, int simulations)
        : price(price), strike(strike), rate(rate), volatility(volatility), time(time), simulations(simulations) {}

    std::vector<double> _simulate(int count) {
        if (count >= simulations) {
            return {};
        }
        double dt = time / simulations;
        double drift = (rate - 0.5 * volatility * volatility) * dt;
        double diffusion = volatility * std::sqrt(dt);
        double price = this->price * std::exp(drift + diffusion * gauss());
        std::vector<double> result = {price};
        result.insert(result.end(), _simulate(count + 1).begin(), _simulate(count + 1).end());
        return result;
    }

    std::vector<double> _payoff(const std::vector<double>& prices) {
        std::vector<double> payoffs;
        for (double p : prices) {
            payoffs.push_back(std::max(p - strike, 0.0));
        }
        return payoffs;
    }

    double price_option() {
        std::vector<double> prices = _simulate(0);
        std::vector<double> payoffs = _payoff(prices);
        double payoff_sum = 0.0;
        for (double payoff : payoffs) {
            payoff_sum += payoff;
        }
        return std::exp(-rate * time) * payoff_sum / simulations;
    }

private:
    double price;
    double strike;
    double rate;
    double volatility;
    double time;
    int simulations;
    std::default_random_engine generator;
    std::normal_distribution<double> distribution;

    double gauss() {
        return distribution(generator);
    }
};

void main() {
    double price = 100;
    double strike = 100;
    double rate = 0.05;
    double volatility = 0.2;
    double time = 1;
    int simulations = 10000;
    MonteCarlo model(price, strike, rate, volatility, time, simulations);
    std::cout << model.price_option() << std::endl;
}