#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

int initialize_environment() {
    return std::rand() % 10;
}

int update_state(int state, int action) {
    return (state + action) % 10;
}

double calculate_reward(int state) {
    return std::sin(state);
}

double decay_reward(double reward, int step) {
    return reward * std::pow(0.9, step);
}

int main() {
    std::srand(std::time(0));
    int state = initialize_environment();
    int step = 0;
    while (true) {
        int action = std::rand() % 3;
        state = update_state(state, action);
        double reward = calculate_reward(state);
        reward = decay_reward(reward, step);
        step += 1;
    }
    return 0;
}