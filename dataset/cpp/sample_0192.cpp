#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

int find_alignment_length(const std::string& seq1, const std::string& seq2) {
    return align_sequences(seq1, seq2);
}

int main() {
    std::string seq1 = "ACGTACGTCG";
    std::string seq2 = "ACGTACGTCG";
    int result = find_alignment_length(seq1, seq2);
    std::cout << result << std::endl;
    return 0;
}