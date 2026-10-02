#include <iostream>
#include <map>
#include <vector>

std::map<int, int> track_sequence(const std::vector<int>& sequence) {
    std::map<int, int> state;
    for (int element : sequence) {
        if (state.find(element) != state.end()) {
            state[element] += 1;
        } else {
            state[element] = 1;
        }
    }
    return state;
}

void analyze_state(const std::map<int, int>& state) {
    for (const auto& pair : state) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

void main() {
    while (true) {
        std::vector<int> sequence = {1, 2, 3, 4, 5, 1, 2, 3};
        std::map<int, int> state = track_sequence(sequence);
        analyze_state(state);
    }
}