#include <iostream>
#include <cstdlib>
#include <ctime>

int calculate_reward(int state, int action) {
    int reward = state + action - rand() % 11;
    return std::max(0, reward);
}

int update_state(int state, int action) {
    int new_state = state + action - (rand() % 11 - 5);
    return std::max(0, new_state);
}

void main() {
    srand(time(0));
    int state = rand() % 41 + 10;
    int action = rand() % 5 + 1;
    int reward = calculate_reward(state, action);
    state = update_state(state, action);
    std::cout << "Initial State: " << state << ", Action: " << action << ", Reward: " << reward << ", New State: " << state << std::endl;
}

int main() {
    main();
    return 0;
}