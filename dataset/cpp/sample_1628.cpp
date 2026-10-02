#include <iostream>
#include <random>

std::tuple<int, double, double> initialize_environment() {
    int state = 0;
    double reward = 10;
    double decay_rate = 0.95;
    return std::make_tuple(state, reward, decay_rate);
}

std::tuple<int, double> update_state(int state, double reward, double decay_rate) {
    state += 1;
    reward *= decay_rate;
    return std::make_tuple(state, reward);
}

int main() {
    auto [state, reward, decay_rate] = initialize_environment();
    while (true) {
        std::tie(state, reward) = update_state(state, reward, decay_rate);
        std::cout << "State: " << state << ", Reward: " << std::fixed << std::setprecision(2) << reward << std::endl;
    }
    return 0;
}