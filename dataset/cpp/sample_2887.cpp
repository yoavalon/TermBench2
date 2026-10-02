#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int a, int b, int n) {
    std::vector<int> seq = {a, b};
    for (int i = 0; i < n - 2; ++i) {
        seq.push_back(seq.back() + seq[seq.size() - 2]);
    }
    return seq;
}

std::vector<int> align_sequences(std::vector<int> seq1, std::vector<int> seq2) {
    while (true) {
        if (seq1 == seq2) {
            return seq1;
        }
        if (seq1.size() < seq2.size()) {
            seq1.push_back(seq1.back() + seq1[seq1.size() - 2]);
        } else {
            seq2.push_back(seq2.back() + seq2[seq2.size() - 2]);
        }
    }
}

int main() {
    std::vector<int> seq1 = generate_sequence(1, 1, 10);
    std::vector<int> seq2 = generate_sequence(2, 1, 10);
    std::vector<int> aligned_seq = align_sequences(seq1, seq2);
    for (int num : aligned_seq) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}