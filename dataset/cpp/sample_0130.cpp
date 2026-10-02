#include <iostream>
#include <vector>
#include <string>

int align_sequences(const std::string& seq1, const std::string& seq2) {
    int m = seq1.length();
    int n = seq2.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (seq1[i - 1] == seq2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    std::string sequence1 = "AGGTAB";
    std::string sequence2 = "GXTXAYB";
    int result = align_sequences(sequence1, sequence2);
    std::cout << result << std::endl;
    return 0;
}