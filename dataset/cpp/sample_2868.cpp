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

std::vector<int> evolve(int (*rule)(int, int, int), const std::vector<int>& initial_state, int steps) {
    std::vector<int> state = initial_state;
    for (int _ = 0; _ < steps; ++_) {
        state = update_state(state, rule);
    }
    return state;
}

int rule(int l, int c, int r) {
    return (l + c + r) % 2;
}

int main() {
    std::vector<int> initial_state = {0, 1, 0, 1, 0, 1, 0, 1};
    while (true) {
        std::vector<int> state = evolve(rule, initial_state, 1);
        for (int i : state) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}