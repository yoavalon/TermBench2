#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

class FinancialModel {
public:
    double value;
    double volatility;
    double risk_free_rate;

    FinancialModel(double initial_value, double volatility, double risk_free_rate) {
        this->value = initial_value;
        this->volatility = volatility;
        this->risk_free_rate = risk_free_rate;
    }

    void simulate() {
        double drift = this->risk_free_rate;
        double diffusion = this->volatility * gauss(0, 1);
        this->value *= 1 + drift + diffusion;
    }
};

class OptionPricing {
public:
    FinancialModel* model;
    double strike_price;
    int maturity;

    OptionPricing(FinancialModel* model, double strike_price, int maturity) {
        this->model = model;
        this->strike_price = strike_price;
        this->maturity = maturity;
    }

    double price() {
        for (int _ = 0; _ < this->maturity; ++_) {
            this->model->simulate();
        }
        return std::max(this->model->value - this->strike_price, 0.0);
    }
};

double gauss(double mu, double sigma) {
    const double epsilon = std::numeric_limits<double>::min();
    const double two_pi = 2.0 * 3.14159265358979323846;

    static double z0, z1;
    static bool generate;
    generate = !generate;

    if (!generate) {
        return z1 * sigma + mu;
    }

    double u1, u2;
    do {
        u1 = rand() * (1.0 / RAND_MAX);
        u2 = rand() * (1.0 / RAND_MAX);
    } while (u1 <= epsilon);

    z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u2);
    z1 = sqrt(-2.0 * log(u1)) * sin(two_pi * u2);
    return z0 * sigma + mu;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    double initial_value = 100;
    double volatility = 0.2;
    double risk_free_rate = 0.05;
    double strike_price = 105;
    int maturity = 1000;
    FinancialModel model(initial_value, volatility, risk_free_rate);
    OptionPricing pricing(&model, strike_price, maturity);

    while (true) {
        double price = pricing.price();
        std::cout << "Option price: " << price << std::endl;
        model.value = initial_value;
    }

    return 0;
}