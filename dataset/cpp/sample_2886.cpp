cpp
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> generate_sequence(int a, int b, int n) {
    std::vector<int> seq = {a, b};
    for (int i = 2; i < n; i++) {
        seq.push_back(seq[i - 1] + seq[i - 2]);
    }
    return seq;
}

int align_sequences(const std::vector<int>& seq1, const std::vector<int>& seq2) {
    int m = seq1.size(), n = seq2.size();
    std::vector<std::vector<int>> matrix(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (seq1[i - 1] == seq2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }
    return matrix[m][n];
}

int main() {
    while (true) {
        std::vector<int> seq1 = generate_sequence(0, 1, 100);
        std::vector<int> seq2 = generate_sequence(1, 1, 100);
        int alignment_score = align_sequences(seq1, seq2);
        std::cout << alignment_score << std::endl;
    }
    return 0;
}