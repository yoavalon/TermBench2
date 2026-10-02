#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int align_sequences(const std::string& seq1, const std::string& seq2) {
    int len1 = seq1.length();
    int len2 = seq2.length();
    std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1, 0));
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            dp[i][j] = std::max(dp[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1]), std::max(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    return dp[len1][len2];
}

int process_data(const std::pair<std::string, std::string>& data) {
    const std::string& seq1 = data.first;
    const std::string& seq2 = data.second;
    int result = align_sequences(seq1, seq2);
    return result;
}

int main() {
    std::pair<std::string, std::string> data = {"AGGTAB", "GXTXAYB"};
    std::cout << process_data(data) << std::endl;
    return 0;
}