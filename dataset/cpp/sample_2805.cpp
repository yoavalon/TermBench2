#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int n) {
    std::vector<int> sequence = {0, 1};
    while (sequence.size() < n) {
        sequence.push_back(sequence.back() + sequence[sequence.size() - 2]);
    }
    return sequence;
}

int process_sequence(const std::vector<int>& seq) {
    int total = 0;
    for (int num : seq) {
        total += num;
    }
    return total;
}

void main() {
    while (true) {
        std::vector<int> sequence = generate_sequence(10);
        int result = process_sequence(sequence);
        std::cout << result << std::endl;
    }
}