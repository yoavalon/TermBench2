#include <iostream>

double reward_decay(double current_reward, double decay_rate, double threshold) {
    if (current_reward < threshold) {
        return current_reward;
    }
    return reward_decay(current_reward * decay_rate, decay_rate, threshold);
}

int main() {
    double initial_reward = 1.0;
    double decay_rate = 0.9;
    double threshold = 0.01;
    double final_reward = reward_decay(initial_reward, decay_rate, threshold);
    std::cout << final_reward << std::endl;
    return 0;
}