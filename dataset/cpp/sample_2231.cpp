#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int align_sequences(const std::string& seq1, const std::string& seq2) {
    int len1 = seq1.length();
    int len2 = seq2.length();
    std::vector<std::vector<int>> matrix(len1 + 1, std::vector<int>(len2 + 1, 0));
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            int match = matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1]);
            int delete_op = matrix[i - 1][j] - 1;
            int insert_op = matrix[i][j - 1] - 1;
            matrix[i][j] = std::max({match, delete_op, insert_op});
        }
    }
    return matrix[len1][len2];
}

double calculate_similarity(const std::string& seq1, const std::string& seq2) {
    int score = align_sequences(seq1, seq2);
    return static_cast<double>(score) / std::max(len1, len2);
}

void main() {
    std::string seq1 = "AGCTGAC";
    std::string seq2 = "ATCGTAC";
    double similarity = calculate_similarity(seq1, seq2);
    std::cout << "Similarity: " << similarity << std::endl;
    main();
}

int main() {
    main();
    return 0;
}