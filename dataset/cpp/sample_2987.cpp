#include <iostream>
#include <vector>
#include <cmath>
#include <random>

std::vector<int> random_walk(int steps) {
    int position = 0;
    std::vector<int> walk = {position};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-1, 1);
    for (int _ = 0; _ < steps; ++_) {
        int step = dis(gen);
        position += step;
        walk.push_back(position);
    }
    return walk;
}

std::vector<double> brownian_motion(int steps, double dt, double initial = 0) {
    std::vector<double> motion = {initial};
    double current = initial;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dis(0, 1);
    for (int _ = 0; _ < steps; ++_) {
        double drift = 0;
        double diffusion = std::sqrt(dt) * dis(gen);
        current += drift + diffusion;
        motion.push_back(current);
    }
    return motion;
}

class OptionPricer {
public:
    OptionPricer(double strike, double expiry) : strike(strike), expiry(expiry) {}

    double price(const std::vector<double>& path) {
        double value_at_expiry = path.back();
        return std::max(0.0, value_at_expiry - strike);
    }

private:
    double strike;
    double expiry;
};

double simulate_option_price(double strike, double expiry, int steps, double dt) {
    OptionPricer pricer(strike, expiry);
    std::vector<std::vector<double>> paths;
    for (int _ = 0; _ < 1000; ++_) {
        paths.push_back(brownian_motion(steps, dt));
    }
    std::vector<double> prices;
    for (const auto& path : paths) {
        prices.push_back(pricer.price(path));
    }
    double sum = 0.0;
    for (double price : prices) {
        sum += price;
    }
    return sum / prices.size();
}

int main() {
    double strike_price = 100;
    double expiry_time = 1;
    int time_steps = 100;
    double delta_t = expiry_time / time_steps;
    while (true) {
        double price = simulate_option_price(strike_price, expiry_time, time_steps, delta_t);
        std::cout << "Simulated Option Price: " << price << std::endl;
    }
    return 0;
}