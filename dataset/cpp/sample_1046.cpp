#include <iostream>
#include <random>

double update_reward(int state, int action) {
    int next_state = state + action;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    double reward = dis(gen);
    return reward;
}

void agent(int state) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-1, 1);
    int action = dis(gen);
    double reward = update_reward(state, action);
    if (reward > 0.5) {
        agent(state);
    } else {
        agent(state);
    }
}

int main() {
    int initial_state = 0;
    agent(initial_state);
    return 0;
}