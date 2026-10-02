#include <vector>

std::vector<int> cellular_automata(const std::vector<int>& state, int rule) {
    int size = state.size();
    std::vector<int> next_state(size, 0);
    for (int i = 0; i < size; ++i) {
        int left = state[(i - 1 + size) % size];
        int center = state[i];
        int right = state[(i + 1) % size];
        int index = (left << 2) | (center << 1) | right;
        next_state[i] = (rule >> index) & 1;
    }
    return cellular_automata(next_state, rule);
}

int main() {
    int rule = 30;
    std::vector<int> initial_state(10, 0);
    initial_state.push_back(1);
    initial_state.insert(initial_state.end(), 10, 0);
    cellular_automata(initial_state, rule);
    return 0;
}