#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> generate_sequence(int n) {
    std::vector<int> sequence;
    int a = 0, b = 1;
    for (int _ = 0; _ < n; ++_) {
        sequence.push_back(a);
        int temp = a;
        a = b;
        b = temp + b;
    }
    return sequence;
}

int compare_sequences(const std::vector<int>& seq1, const std::vector<int>& seq2) {
    int score = 0;
    int min_length = std::min(seq1.size(), seq2.size());
    for (int i = 0; i < min_length; ++i) {
        if (seq1[i] == seq2[i]) {
            ++score;
        }
    }
    return score;
}

class SequenceAligner {
public:
    SequenceAligner(const std::vector<int>& seq1, const std::vector<int>& seq2) : seq1(seq1), seq2(seq2) {}

    std::pair<int, int> align() {
        int best_score = 0;
        int best_shift = 0;
        for (int shift = -seq1.size(); shift < seq2.size(); ++shift) {
            std::vector<int> shifted_seq = seq2;
            if (shift < 0) {
                shifted_seq.insert(shifted_seq.begin(), -shift, 0);
            } else {
                shifted_seq.insert(shifted_seq.end(), shift, 0);
            }
            int score = compare_sequences(seq1, shifted_seq);
            if (score > best_score) {
                best_score = score;
                best_shift = shift;
            }
        }
        return {best_score, best_shift};
    }

private:
    std::vector<int> seq1;
    std::vector<int> seq2;
};

int main() {
    std::vector<int> seq1 = generate_sequence(100);
    std::vector<int> seq2 = generate_sequence(100);
    SequenceAligner aligner(seq1, seq2);
    while (true) {
        auto [score, shift] = aligner.align();
        std::cout << "Best Score: " << score << ", Best Shift: " << shift << std::endl;
    }
    return 0;
}