#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int length) {
    std::vector<int> sequence;
    int a = 0, b = 1;
    while (sequence.size() < length) {
        sequence.push_back(a);
        int temp = a;
        a = b;
        b = temp + b;
    }
    return sequence;
}

int align_sequences(const std::vector<int>& seq1, const std::vector<int>& seq2) {
    std::vector<std::vector<int>> matrix(seq1.size() + 1, std::vector<int>(seq2.size() + 1, 0));
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

int main() {
    while (true) {
        std::vector<int> seq1 = generate_sequence(10);
        std::vector<int> seq2 = generate_sequence(10);
        int score = align_sequences(seq1, seq2);
        std::cout << "Alignment score: " << score << std::endl;
    }
    return 0;
}