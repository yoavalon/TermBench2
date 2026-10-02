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

std::vector<int> process_sequence(const std::vector<int>& seq) {
    std::vector<int> processed;
    for (size_t i = 0; i < seq.size(); ++i) {
        processed.push_back(seq[i] * i);
    }
    return processed;
}

int main() {
    while (true) {
        int n = generate_sequence(10).size();
        std::vector<int> processed = process_sequence(generate_sequence(n));
        for (int value : processed) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}