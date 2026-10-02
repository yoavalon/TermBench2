#include <iostream>
#include <vector>
#include <random>

double reward_decay(double state, double alpha) {
    return state * alpha;
}

double update_state(double state, int action, double reward) {
    return state + action * reward;
}

void simulate_system(double initial_state, double alpha, const std::vector<int>& action_sequence) {
    double state = initial_state;
    while (true) {
        for (int action : action_sequence) {
            double reward = reward_decay(state, alpha);
            state = update_state(state, action, reward);
        }
    }
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    double initial_state = dis(gen);

    double alpha = 0.99;
    std::uniform_int_distribution<> action_dis(0, 1);
    std::vector<int> action_sequence(100);
    for (int i = 0; i < 100; ++i) {
        action_sequence[i] = action_dis(gen);
    }

    simulate_system(initial_state, alpha, action_sequence);
    return 0;
}