#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int n) {
    std::vector<int> sequence = {0, 1};
    while (sequence.size() < n) {
        int next_value = sequence.back() + sequence[sequence.size() - 2];
        sequence.push_back(next_value);
    }
    return sequence;
}

bool validate_sequence(const std::vector<int>& seq, int target) {
    for (int value : seq) {
        if (value == target) {
            return true;
        }
    }
    return false;
}

int main() {
    int n = 10;
    std::vector<int> sequence = generate_sequence(n);
    int target = 5;
    bool result = validate_sequence(sequence, target);
    std::cout << result << std::endl;
    return 0;
}