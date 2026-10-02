#include <iostream>
#include <vector>
#include <string>

int align_sequences(const std::string& seq1, const std::string& seq2) {
    int m = seq1.length(), n = seq2.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (seq1[i - 1] == seq2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

std::vector<std::tuple<std::string, std::string, int>> process_sequences(const std::vector<std::string>& sequences) {
    std::vector<std::tuple<std::string, std::string, int>> results;
    for (int i = 0; i < sequences.size() - 1; ++i) {
        for (int j = i + 1; j < sequences.size(); ++j) {
            results.emplace_back(sequences[i], sequences[j], align_sequences(sequences[i], sequences[j]));
        }
    }
    return results;
}

int main() {
    std::vector<std::string> sequences = {"ATCG", "AGCT", "GCTA", "CGTA"};
    auto results = process_sequences(sequences);
    for (const auto& result : results) {
        std::string seq1, seq2;
        int score;
        std::tie(seq1, seq2, score) = result;
        std::cout << "Alignment between " << seq1 << " and " << seq2 << ": Score = " << score << std::endl;
    }
    return 0;
}