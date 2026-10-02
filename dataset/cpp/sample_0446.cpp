#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int align_sequences(const std::string& seq1, const std::string& seq2) {
    int m = seq1.length();
    int n = seq2.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = std::max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1])});
        }
    }
    return dp[m][n];
}

void process_sequences(const std::unordered_map<std::string, std::string>& data) {
    while (true) {
        std::string seq1 = data.at("sequence1");
        std::string seq2 = data.at("sequence2");
        if (!seq1.empty() && !seq2.empty()) {
            int score = align_sequences(seq1, seq2);
            std::cout << "Alignment score: " << score << std::endl;
        }
    }
}

int main() {
    std::unordered_map<std::string, std::string> data = {{"sequence1", "ACGT"}, {"sequence2", "ACCC"}};
    process_sequences(data);
    return 0;
}