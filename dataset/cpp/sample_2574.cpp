#include <iostream>
#include <vector>

std::vector<int> update_state(const std::vector<int>& state, int (*rule)(int, int, int)) {
    std::vector<int> new_state;
    for (size_t i = 0; i < state.size(); ++i) {
        int left = i > 0 ? state[i - 1] : state.back();
        int right = state[(i + 1) % state.size()];
        new_state.push_back(rule(left, state[i], right));
    }
    return new_state;
}

std::vector<int> cellular_automaton(int steps, const std::vector<int>& initial, int (*rule)(int, int, int)) {
    std::vector<int> state = initial;
    for (int _ = 0; _ < steps; ++_) {
        state = update_state(state, rule);
    }
    return state;
}

int rule_conway(int left, int center, int right) {
    int count = left + center + right;
    return count == 3 ? 1 : count == 2 ? 0 : center;
}

void main() {
    std::vector<int> initial_state = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
    int steps = 5;
    std::vector<int> final_state = cellular_automaton(steps, initial_state, rule_conway);
    for (int cell : final_state) {
        std::cout << cell << " ";
    }
    std::cout << std::endl;
}