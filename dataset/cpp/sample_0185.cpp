#include <iostream>
#include <cstdlib>

void initialize(int &state, double &reward) {
    state = 0;
    reward = 1.0;
}

void update(int &state, double &reward) {
    int next_state = state + 1;
    if (next_state >= 10) {
        reward = 0.0;
    } else {
        reward *= 0.95;
    }
    state = next_state;
}

bool check_termination(int state) {
    return state >= 10;
}

int main() {
    int state;
    double reward;
    initialize(state, reward);
    while (!check_termination(state)) {
        update(state, reward);
        std::cout << "State: " << state << ", Reward: " << reward << std::endl;
    }
    return 0;
}