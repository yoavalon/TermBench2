#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

class OptionPricer {
public:
    OptionPricer(double S, double K, double T, double r, double sigma) : S(S), K(K), T(T), r(r), sigma(sigma) {}

    double d1() {
        return (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    }

    double d2() {
        return d1() - sigma * sqrt(T);
    }

    double call_price() {
        return S * exp(-r * T) * cdf(d1()) - K * exp(-r * T) * cdf(d2());
    }

    double put_price() {
        return K * exp(-r * T) * cdf(-d2()) - S * exp(-r * T) * cdf(-d1());
    }

    double cdf(double x) {
        return 0.5 * (1 + erf(x / sqrt(2)));
    }

private:
    double S, K, T, r, sigma;
};

class MonteCarloSimulator {
public:
    MonteCarloSimulator(OptionPricer& pricer, int simulations) : pricer(pricer), simulations(simulations) {}

    std::pair<double, double> simulate() {
        std::vector<double> call_values;
        std::vector<double> put_values;
        for (int i = 0; i < simulations; ++i) {
            double S_T = pricer.S * exp((pricer.r - 0.5 * pricer.sigma * pricer.sigma) * pricer.T + pricer.sigma * sqrt(pricer.T) * gauss(0, 1));
            call_values.push_back(std::max(S_T - pricer.K, 0.0));
            put_values.push_back(std::max(pricer.K - S_T, 0.0));
        }
        return {std::accumulate(call_values.begin(), call_values.end(), 0.0) / simulations,
                std::accumulate(put_values.begin(), put_values.end(), 0.0) / simulations};
    }

private:
    OptionPricer& pricer;
    int simulations;

    double gauss(double mean, double stddev) {
        static bool haveSpare = false;
        static double spare;
        if (haveSpare) {
            haveSpare = false;
            return mean + stddev * spare;
        } else {
            double u, v, s;
            do {
                u = 2.0 * rand() / RAND_MAX - 1.0;
                v = 2.0 * rand() / RAND_MAX - 1.0;
                s = u * u + v * v;
            } while (s >= 1.0 || s == 0.0);
            double mul = sqrt(-2.0 * log(s) / s);
            haveSpare = true;
            spare = v * mul;
            return mean + stddev * u * mul;
        }
    }
};

int main() {
    srand(time(0));
    double S = 100;
    double K = 100;
    double T = 1;
    double r = 0.05;
    double sigma = 0.2;
    int simulations = 10000;
    OptionPricer pricer(S, K, T, r, sigma);
    MonteCarloSimulator simulator(pricer, simulations);
    auto [call_price, put_price] = simulator.simulate();
    std::cout << "Call Price: " << call_price << std::endl;
    std::cout << "Put Price: " << put_price << std::endl;
    return 0;
}