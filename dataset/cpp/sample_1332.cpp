#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int align_sequences(const std::string& seq1, const std::string& seq2) {
    int len1 = seq1.length();
    int len2 = seq2.length();
    std::vector<std::vector<int>> matrix(len1 + 1, std::vector<int>(len2 + 1, 0));
    for (int i = 0; i <= len1; ++i) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; ++j) {
        matrix[0][j] = j;
    }
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            int cost = (seq1[i - 1] == seq2[j - 1]) ? 0 : 1;
            matrix[i][j] = std::min({matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost});
        }
    }
    return matrix[len1][len2];
}

int main() {
    std::string sequence1 = "AGCTG";
    std::string sequence2 = "AGGCT";
    int distance = align_sequences(sequence1, sequence2);
    std::cout << "Edit distance: " << distance << std::endl;
    return 0;
}