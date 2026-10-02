#include <iostream>
#include <vector>

int update_state(int state, int delta) {
    return state + delta;
}

std::vector<int> compute_sequence(int steps, int initial, int increment) {
    std::vector<int> result;
    int current = initial;
    for (int i = 0; i < steps; ++i) {
        result.push_back(current);
        current = update_state(current, increment);
    }
    return result;
}

void main() {
    int steps = 10;
    int initial = 0;
    int increment = 1;
    std::vector<int> sequence = compute_sequence(steps, initial, increment);
    for (int value : sequence) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}