#include <iostream>
#include <vector>
#include <unordered_map>

int process_sequence(const std::vector<int>& sequence) {
    int state = 0;
    std::unordered_map<int, std::unordered_map<int, int>> transitions = {
        {0, {{0, 1}, {1, 2}}},
        {1, {{0, 3}, {1, 0}}},
        {2, {{0, 0}, {1, 3}}},
        {3, {{0, 2}, {1, 1}}}
    };
    for (int bit : sequence) {
        state = transitions[state][bit];
    }
    return state;
}

void main() {
    std::vector<int> sequence = {0, 1, 0, 1, 1, 0, 0};
    int result = process_sequence(sequence);
    std::cout << result << std::endl;
}