#include <iostream>
#include <vector>
#include <string>

void mutate_sequence(std::vector<char>& seq, const std::vector<char>& mutations) {
    for (size_t i = 0; i < mutations.size(); ++i) {
        if (i < seq.size()) {
            seq[i] = mutations[i];
        }
    }
}

int align_sequences(const std::vector<char>& seq1, const std::vector<char>& seq2, const std::vector<char>& mutations) {
    std::vector<char> mutated_seq1 = seq1;
    mutate_sequence(mutated_seq1, mutations);
    int score = 0;
    for (size_t i = 0; i < mutated_seq1.size() && i < seq2.size(); ++i) {
        if (mutated_seq1[i] == seq2[i]) {
            ++score;
        }
    }
    return score;
}

int main() {
    std::vector<char> seq1 = {'A', 'T', 'C', 'G', 'A'};
    std::vector<char> seq2 = {'A', 'C', 'C', 'G', 'T'};
    std::vector<char> mutations = {'C', 'G', 'T', 'A', 'G'};
    while (true) {
        int score = align_sequences(seq1, seq2, mutations);
        std::cout << score << std::endl;
    }
    return 0;
}