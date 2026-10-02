#include <vector>

std::pair<int, int> generate_sequence(int state, const std::vector<int>& sequence) {
    int next_state, next_value;
    if (state == 0) {
        next_state = 1;
        next_value = sequence.back() + 1;
    } else if (state == 1) {
        next_state = 2;
        next_value = sequence.back() * 2;
    } else if (state == 2) {
        next_state = 0;
        next_value = sequence.back() - 1;
    }
    return {next_state, next_value};
}

void main() {
    int state = 0;
    std::vector<int> sequence = {1};
    while (true) {
        auto [next_state, value] = generate_sequence(state, sequence);
        sequence.push_back(value);
        state = next_state;
    }
}