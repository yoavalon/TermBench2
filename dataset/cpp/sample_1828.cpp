#include <iostream>
#include <vector>
#include <string>

int process_sequences(const std::string& seq1, const std::string& seq2) {
    std::vector<std::vector<int>> align_matrix(seq1.length() + 1, std::vector<int>(seq2.length() + 1, 0));
    for (int i = 1; i <= seq1.length(); ++i) {
        for (int j = 1; j <= seq2.length(); ++j) {
            int match = (seq1[i - 1] == seq2[j - 1]) ? align_matrix[i - 1][j - 1] + 1 : 0;
            align_matrix[i][j] = std::max({align_matrix[i][j - 1], align_matrix[i - 1][j], match});
        }
    }
    return align_matrix[seq1.length()][seq2.length()];
}

int main() {
    std::string seq1 = "ACGT";
    std::string seq2 = "ACCGT";
    int result = process_sequences(seq1, seq2);
    std::cout << result << std::endl;
    return 0;
}