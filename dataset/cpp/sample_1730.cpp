#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>

std::string generate_sequence(int length) {
    std::string result;
    std::srand(std::time(nullptr));
    for (int i = 0; i < length; ++i) {
        int random_index = std::rand() % 4;
        result += "ATCG"[random_index];
    }
    return result;
}

int align_sequences(const std::string& seq1, const std::string& seq2) {
    int matrix[seq1.size() + 1][seq2.size() + 1];
    for (int i = 0; i <= seq1.size(); ++i) {
        for (int j = 0; j <= seq2.size(); ++j) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 1; i <= seq1.size(); ++i) {
        for (int j = 1; j <= seq2.size(); ++j) {
            if (seq1[i - 1] == seq2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }
    return matrix[seq1.size()][seq2.size()];
}

std::string mutate_sequence(const std::string& seq) {
    std::string result = seq;
    std::srand(std::time(nullptr));
    for (int i = 0; i < seq.size(); ++i) {
        if (static_cast<double>(std::rand()) / RAND_MAX < 0.1) {
            result[i] = "ATCG"[std::rand() % 4];
        }
    }
    return result;
}

class SequenceAligner {
public:
    SequenceAligner(const std::string& seq1, const std::string& seq2) : seq1(seq1), seq2(seq2) {}

    void update_sequences() {
        seq1 = mutate_sequence(seq1);
        seq2 = mutate_sequence(seq2);
    }

    void run_alignment() {
        while (true) {
            int alignment_score = align_sequences(seq1, seq2);
            std::cout << "Alignment Score: " << alignment_score << std::endl;
            update_sequences();
        }
    }

private:
    std::string seq1;
    std::string seq2;
};

int main() {
    std::string seq1 = generate_sequence(100);
    std::string seq2 = generate_sequence(100);
    SequenceAligner aligner(seq1, seq2);
    aligner.run_alignment();
    return 0;
}