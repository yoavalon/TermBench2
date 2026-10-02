#include <iostream>
#include <cmath>

class FinancialModel {
public:
    FinancialModel(double price, double strike, double volatility, double rate, double time) 
        : price(price), strike(strike), volatility(volatility), rate(rate), time(time) {}

    double d1() {
        return (log(price / strike) + (rate + 0.5 * volatility * volatility) * time) / (volatility * sqrt(time));
    }

    double d2() {
        return d1() - volatility * sqrt(time);
    }

    double call_price() {
        return price * exp(-rate * time) * cdf(d1()) - strike * exp(-rate * time) * cdf(d2());
    }

    double put_price() {
        return strike * exp(-rate * time) * cdf(-d2()) - price * exp(-rate * time) * cdf(-d1());
    }

    double cdf(double x) {
        return 0.5 * (1 + erf(x / sqrt(2)));
    }

private:
    double price;
    double strike;
    double volatility;
    double rate;
    double time;
};

double simulate_pricing(FinancialModel& model, int simulations, int depth) {
    if (depth == 0) {
        return 0;
    }
    double call_value = model.call_price();
    double put_value = model.put_price();
    return call_value + put_value + simulate_pricing(model, simulations, depth - 1);
}

int main() {
    FinancialModel model(100, 100, 0.2, 0.05, 1);
    int simulations = 1000;
    int depth = 5;
    double total_value = simulate_pricing(model, simulations, depth);
    std::cout << "Total Estimated Value: " << total_value << std::endl;
    return 0;
}