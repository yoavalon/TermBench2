#include <iostream>
#include <vector>

std::vector<int> mutate_state(const std::vector<int>& state, int rate) {
    std::vector<int> new_state = state;
    for (size_t i = 0; i < new_state.size(); ++i) {
        if (new_state[i] > 0) {
            new_state[i] -= rate;
        } else {
            new_state[i] = 0;
        }
    }
    return new_state;
}

void simulate_state(const std::vector<int>& initial_state, int rate) {
    std::vector<int> state = initial_state;
    while (true) {
        state = mutate_state(state, rate);
        for (int val : state) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<int> initial_state = {10, 20, 30, 40, 50};
    int mutation_rate = 5;
    simulate_state(initial_state, mutation_rate);
    return 0;
}