#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

double update_reward(double state, int action) {
    if (action == 0) {
        return state * 0.95;
    } else {
        return state * 0.9;
    }
}

double simulate_episodes(int num_episodes, int max_steps) {
    std::vector<double> rewards;
    for (int i = 0; i < num_episodes; ++i) {
        double state = 1.0;
        for (int j = 0; j < max_steps; ++j) {
            int action = std::rand() % 2;
            state = update_reward(state, action);
            if (state < 0.1) {
                break;
            }
        }
        rewards.push_back(state);
    }
    double sum = 0.0;
    for (double reward : rewards) {
        sum += reward;
    }
    return sum / rewards.size();
}

int main() {
    std::srand(std::time(0));
    double result = simulate_episodes(100, 1000);
    std::cout << result << std::endl;
    return 0;
}