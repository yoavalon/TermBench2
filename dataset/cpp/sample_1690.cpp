#include <iostream>
#include <random>
#include <cmath>

double generate_random_price() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 100);
    return dis(gen);
}

double simulate_option_price(int days, double strike) {
    double price = generate_random_price();
    for (int _ = 0; _ < days; ++_) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> dis(0, 1);
        price += dis(gen);
        if (price < 0) {
            price = 0;
        }
    }
    return std::max(price - strike, 0.0);
}

int main() {
    while (true) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 365);
        int days = dis(gen);
        std::uniform_real_distribution<> dis2(0, 100);
        double strike = dis2(gen);
        double result = simulate_option_price(days, strike);
        std::cout << "Option price: " << result << std::endl;
    }
    return 0;
}