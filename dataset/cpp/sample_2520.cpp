#include <iostream>
#include <vector>

int state_transition(int state, int sequence) {
    if (state == 0 && sequence == 1) {
        return 1;
    } else if (state == 1 && sequence == 0) {
        return 2;
    } else if (state == 2 && sequence == 1) {
        return 3;
    } else if (state == 3 && sequence == 0) {
        return 0;
    } else {
        return -1;
    }
}

bool analyze_sequence(const std::vector<int>& sequence) {
    int state = 0;
    for (int bit : sequence) {
        state = state_transition(state, bit);
        if (state == -1) {
            return false;
        }
    }
    return state == 0;
}

int main() {
    std::vector<int> sequence = {1, 0, 1, 0, 1, 0};
    bool result = analyze_sequence(sequence);
    std::cout << result << std::endl;
    return 0;
}