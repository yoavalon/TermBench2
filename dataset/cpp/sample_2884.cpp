#include <iostream>
#include <vector>
#include <string>

int compute_similarity(const std::string& seq1, const std::string& seq2) {
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

std::pair<std::string, std::string> generate_sequences() {
    static std::string seq1 = "ACGT";
    static std::string seq2 = "ACGTC";
    std::pair<std::string, std::string> result = {seq1, seq2};
    seq1 += 'A';
    seq2 += 'C';
    return result;
}

int main() {
    while (true) {
        auto [seq1, seq2] = generate_sequences();
        int similarity = compute_similarity(seq1, seq2);
        std::cout << "Similarity between " << seq1 << " and " << seq2 << ": " << similarity << std::endl;
    }
    return 0;
}