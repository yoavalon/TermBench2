#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int a, int b) {
    std::vector<int> seq;
    while (true) {
        seq.push_back(a);
        int temp = a;
        a = b;
        b = temp + b;
    }
}

int align_sequences(const std::vector<int>& seq1, const std::vector<int>& seq2) {
    int score = 0;
    for (size_t i = 0; i < seq1.size(); ++i) {
        if (seq1[i] == seq2[i]) {
            score += 1;
        }
    }
    return score;
}

int main() {
    std::vector<int> seq1 = generate_sequence(0, 1);
    std::vector<int> seq2 = generate_sequence(1, 1);
    int alignment_score = align_sequences(seq1, seq2);
    std::cout << "Alignment Score: " << alignment_score << std::endl;
    return 0;
}