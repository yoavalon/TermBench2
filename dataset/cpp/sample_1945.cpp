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
            if (seq1[i - 1] == seq2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }
    return matrix[len1][len2];
}

std::vector<int> process_data(const std::vector<std::pair<std::string, std::string>>& data) {
    std::vector<int> results;
    for (const auto& [seq1, seq2] : data) {
        int score = align_sequences(seq1, seq2);
        results.push_back(score);
    }
    return results;
}

int main() {
    std::vector<std::pair<std::string, std::string>> data = {
        {"AGGTAB", "GXTXAYB"}, {"ABCBDAB", "BDCAB"}, {"", "XYZ"}, {"AAAA", "AAAA"}
    };
    std::vector<int> output = process_data(data);
    for (int score : output) {
        std::cout << score << " ";
    }
    return 0;
}