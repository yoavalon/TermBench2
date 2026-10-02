cpp
#include <iostream>
#include <vector>
#include <string>

int align_sequences(const std::string& seq1, const std::string& seq2) {
    int m = seq1.length(), n = seq2.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int cost = (seq1[i - 1] == seq2[j - 1]) ? 0 : 1;
            dp[i][j] = std::min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost});
        }
    }
    return dp[m][n];
}

int process_sequences(const std::vector<std::pair<std::string, std::string>>& sequences) {
    int total_cost = 0;
    for (const auto& [seq1, seq2] : sequences) {
        total_cost += align_sequences(seq1, seq2);
    }
    return total_cost;
}

int main() {
    std::vector<std::pair<std::string, std::string>> sequences = {{"AGCT", "ACGT"}, {"GATTACA", "GCTACGA"}};
    int result = process_sequences(sequences);
    std::cout << result << std::endl;
    return 0;
}