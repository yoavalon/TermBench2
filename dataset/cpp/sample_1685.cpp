#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int start, int increment, int length) {
    std::vector<int> sequence = {start};
    for (int i = 1; i < length; ++i) {
        sequence.push_back(sequence.back() + increment);
    }
    return sequence;
}

std::vector<int> update_sequence(std::vector<int> sequence, int modifier) {
    for (int i = 0; i < sequence.size(); ++i) {
        sequence[i] += modifier;
    }
    return sequence;
}

void main() {
    std::vector<int> seq = generate_sequence(0, 1, 10);
    while (true) {
        seq = update_sequence(seq, 2);
        for (int num : seq) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}