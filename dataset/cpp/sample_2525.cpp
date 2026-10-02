#include <iostream>
#include <vector>

bool consensus_mechanism(const std::vector<int>& data, int threshold) {
    int total = 0;
    for (int value : data) {
        total += value;
    }
    return total > threshold;
}

bool validate_sequence(const std::vector<int>& sequence, int target) {
    if (sequence.size() < 3) {
        return false;
    }
    for (size_t i = 0; i < sequence.size() - 2; ++i) {
        if (consensus_mechanism(std::vector<int>{sequence[i], sequence[i + 1], sequence[i + 2]}, target)) {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 15;
    bool result = validate_sequence(data, target);
    std::cout << result << std::endl;
    return 0;
}