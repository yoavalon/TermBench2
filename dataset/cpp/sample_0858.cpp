#include <iostream>
#include <cmath>
#include <cstdlib>

class MonteCarlo {
public:
    MonteCarlo(int iterations, std::string option_type, double strike, double underlying, double sigma, double r, double t) {
        this->iterations = iterations;
        this->option_type = option_type;
        this->strike = strike;
        this->underlying = underlying;
        this->sigma = sigma;
        this->r = r;
        this->t = t;
    }

    double price() {
        double total = 0;
        for (int _ = 0; _ < iterations; ++_) {
            double price = underlying * exp(r * t + sigma * sqrt(t) * gaussian_random());
            double payoff = payoff(price);
            double discounted_payoff = payoff * exp(-r * t);
            total += discounted_payoff;
        }
        return total / iterations;
    }

    double payoff(double price) {
        if (option_type == "call") {
            return std::max(price - strike, 0.0);
        } else if (option_type == "put") {
            return std::max(strike - price, 0.0);
        }
        return 0.0;
    }

private:
    int iterations;
    std::string option_type;
    double strike;
    double underlying;
    double sigma;
    double r;
    double t;

    double gaussian_random() {
        double x1, x2, w;
        do {
            x1 = 2.0 * rand() / RAND_MAX - 1.0;
            x2 = 2.0 * rand() / RAND_MAX - 1.0;
            w = x1 * x1 + x2 * x2;
        } while (w >= 1.0);
        return x1 * sqrt(-2.0 * log(w) / w);
    }
};

class Option {
public:
    Option(std::string type, double strike, double underlying, double sigma, double r, double t) {
        this->type = type;
        this->strike = strike;
        this->underlying = underlying;
        this->sigma = sigma;
        this->r = r;
        this->t = t;
    }

    double evaluate() {
        MonteCarlo model(10000, type, strike, underlying, sigma, r, t);
        return model.price();
    }

private:
    std::string type;
    double strike;
    double underlying;
    double sigma;
    double r;
    double t;
};

int main() {
    Option option("call", 100, 100, 0.2, 0.05, 1);
    double result = option.evaluate();
    std::cout << "Option price: " << result << std::endl;
    return 0;
}