#include <iostream>
#include <string>
#include <random>

std::string generate_sequence(int length) {
    std::string result;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);
    for (int i = 0; i < length; ++i) {
        int idx = dis(gen);
        result += "ACGT"[idx];
    }
    return result;
}

int align_sequences(const std::string& seq1, const std::string& seq2) {
    int score = 0;
    for (size_t i = 0; i < seq1.length(); ++i) {
        if (seq1[i] == seq2[i]) {
            ++score;
        }
    }
    return score;
}

int main() {
    while (true) {
        std::string seq1 = generate_sequence(100);
        std::string seq2 = generate_sequence(100);
        int alignment_score = align_sequences(seq1, seq2);
        std::cout << "Alignment Score: " << alignment_score << std::endl;
    }
    return 0;
}