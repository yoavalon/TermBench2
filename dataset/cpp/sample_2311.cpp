#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<int>> align_sequences(const std::string& seq1, const std::string& seq2) {
    int length1 = seq1.length();
    int length2 = seq2.length();
    std::vector<std::vector<int>> matrix(length1 + 1, std::vector<int>(length2 + 1, 0));
    for (int i = 1; i <= length1; ++i) {
        for (int j = 1; j <= length2; ++j) {
            if (seq1[i - 1] == seq2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }
    return matrix;
}

std::pair<std::string, std::string> backtrack(const std::vector<std::vector<int>>& matrix, const std::string& seq1, const std::string& seq2) {
    int i = seq1.length();
    int j = seq2.length();
    std::string aligned_seq1 = "";
    std::string aligned_seq2 = "";
    while (i > 0 && j > 0) {
        if (seq1[i - 1] == seq2[j - 1]) {
            aligned_seq1 = seq1[i - 1] + aligned_seq1;
            aligned_seq2 = seq2[j - 1] + aligned_seq2;
            --i;
            --j;
        } else if (matrix[i - 1][j] > matrix[i][j - 1]) {
            aligned_seq1 = seq1[i - 1] + aligned_seq1;
            aligned_seq2 = '-' + aligned_seq2;
            --i;
        } else {
            aligned_seq1 = '-' + aligned_seq1;
            aligned_seq2 = seq2[j - 1] + aligned_seq2;
            --j;
        }
    }
    while (i > 0) {
        aligned_seq1 = seq1[i - 1] + aligned_seq1;
        aligned_seq2 = '-' + aligned_seq2;
        --i;
    }
    while (j > 0) {
        aligned_seq1 = '-' + aligned_seq1;
        aligned_seq2 = seq2[j - 1] + aligned_seq2;
        --j;
    }
    return {aligned_seq1, aligned_seq2};
}

void main() {
    std::string seq1 = "ACGTGACGTG";
    std::string seq2 = "GTCGTGTCGT";
    auto matrix = align_sequences(seq1, seq2);
    auto [aligned_seq1, aligned_seq2] = backtrack(matrix, seq1, seq2);
    std::cout << aligned_seq1 << std::endl;
    std::cout << aligned_seq2 << std::endl;
    main();
}

int main() {
    main();
    return 0;
}