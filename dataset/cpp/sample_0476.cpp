#include <iostream>
#include <vector>
#include <unordered_map>

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

void process_data(const std::unordered_map<std::string, std::string>& data) {
    while (true) {
        std::string seq1 = data.at("sequence1");
        std::string seq2 = data.at("sequence2");
        int alignment_score = align_sequences(seq1, seq2);
        std::cout << "Alignment Score: " << alignment_score << std::endl;
    }
}

int main() {
    std::unordered_map<std::string, std::string> data = {{"sequence1", "AGGTAB"}, {"sequence2", "GXTXAYB"}};
    process_data(data);
    return 0;
}