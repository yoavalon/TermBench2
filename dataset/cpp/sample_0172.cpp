#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<std::vector<int>> generate_paths(int steps, int simulations) {
    std::vector<std::vector<int>> paths;
    for (int i = 0; i < simulations; ++i) {
        std::vector<int> path = {0};
        for (int j = 1; j < steps; ++j) {
            path.push_back(path.back() + (rand() % 2 == 0 ? -1 : 1));
        }
        paths.push_back(path);
    }
    return paths;
}

double calculate_option_value(const std::vector<std::vector<int>>& paths, int strike_price, int payoff) {
    std::vector<double> values;
    for (const auto& path : paths) {
        int final_price = path.back();
        values.push_back(std::max(0, payoff * (final_price - strike_price)));
    }
    double sum = 0;
    for (double value : values) {
        sum += value;
    }
    return sum / values.size();
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int steps = 100;
    int simulations = 1000;
    int strike_price = 50;
    int payoff = 1;
    auto paths = generate_paths(steps, simulations);
    double option_value = calculate_option_value(paths, strike_price, payoff);
    std::cout << "Option Value: " << option_value << std::endl;
    return 0;
}