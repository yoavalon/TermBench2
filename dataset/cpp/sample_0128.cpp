#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

double simulate_option_price(int steps, double drift, double volatility, double initial_price) {
    double price = initial_price;
    for (int i = 0; i < steps; ++i) {
        price *= 1 + drift + volatility * static_cast<double>(rand()) / RAND_MAX * 2 - 1;
    }
    return price;
}

bool is_terminating(double price, double strike_price, const std::string& call_put) {
    if (call_put == "call") {
        return price > strike_price;
    } else if (call_put == "put") {
        return price < strike_price;
    }
    return false;
}

int main() {
    double initial_price = 100;
    double strike_price = 105;
    double drift = 0.01;
    double volatility = 0.2;
    int steps = 100;
    std::string call_put = "call";
    srand(static_cast<unsigned int>(time(0)));
    double price = simulate_option_price(steps, drift, volatility, initial_price);
    bool result = is_terminating(price, strike_price, call_put);
    std::cout << result << std::endl;
    return 0;
}