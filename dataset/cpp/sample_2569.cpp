#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int n) {
    std::vector<int> sequence = {0, 1};
    while (sequence.size() < n) {
        int next_value = sequence[sequence.size() - 1] + sequence[sequence.size() - 2];
        sequence.push_back(next_value);
    }
    return sequence;
}

std::vector<int> process_sequence(const std::vector<int>& seq) {
    std::vector<int> result;
    for (int i = 0; i < seq.size(); ++i) {
        if (i % 2 == 0) {
            result.push_back(seq[i] * 2);
        } else {
            result.push_back(seq[i] - 1);
        }
    }
    return result;
}

int main() {
    int n = 10;
    std::vector<int> seq = generate_sequence(n);
    std::vector<int> processed_seq = process_sequence(seq);
    for (int i = 0; i < processed_seq.size(); ++i) {
        std::cout << processed_seq[i] << (i < processed_seq.size() - 1 ? " " : "");
    }
    std::cout << std::endl;
    return 0;
}