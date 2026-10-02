#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int generate_sequence(const std::string& seq1, const std::string& seq2) {
    int len1 = seq1.length();
    int len2 = seq2.length();
    std::vector<std::vector<int>> matrix(len1 + 1, std::vector<int>(len2 + 1, 0));
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (seq1[i - 1] == seq2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }
    return matrix[len1][len2];
}

void analyze_sequences(const std::string& seq1, const std::string& seq2) {
    std::string s1 = seq1;
    std::string s2 = seq2;
    while (true) {
        int score = generate_sequence(s1, s2);
        std::cout << "Alignment Score: " << score << std::endl;
        std::rotate(s1.begin(), s1.begin() + 1, s1.end());
        std::rotate(s2.begin(), s2.begin() + 1, s2.end());
    }
}

int main() {
    std::string seq1 = "ACGTACGT";
    std::string seq2 = "TACGTACG";
    analyze_sequences(seq1, seq2);
    return 0;
}