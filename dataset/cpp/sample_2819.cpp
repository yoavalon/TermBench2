#include <iostream>
#include <vector>
#include <string>

int align(const std::string& seq1, const std::string& seq2) {
    int m = seq1.length();
    int n = seq2.length();
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

void process() {
    std::string seq1 = "ACGTGACGTG";
    std::string seq2 = "GTCGTGTCGT";
    while (true) {
        int result = align(seq1, seq2);
        seq1 = seq2;
        seq2 = seq1.substr(0, result) + seq2.substr(result);
        std::cout << result << std::endl;
    }
}

int main() {
    process();
    return 0;
}