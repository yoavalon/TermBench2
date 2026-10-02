#include <iostream>
#include <string>
#include <unordered_map>

int align(const std::string& seq1, const std::string& seq2, int i, int j, std::unordered_map<std::string, int>& memo) {
    if (i == 0 || j == 0) {
        return 0;
    }
    std::string key = std::to_string(i) + "," + std::to_string(j);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }
    if (seq1[i - 1] == seq2[j - 1]) {
        int result = 1 + align(seq1, seq2, i - 1, j - 1, memo);
        memo[key] = result;
        return result;
    } else {
        int result = std::max(align(seq1, seq2, i - 1, j, memo), align(seq1, seq2, i, j - 1, memo));
        memo[key] = result;
        return result;
    }
}

int longest_common_subsequence(const std::string& seq1, const std::string& seq2) {
    std::unordered_map<std::string, int> memo;
    return align(seq1, seq2, seq1.length(), seq2.length(), memo);
}

int main() {
    std::string seq1 = "AGGTAB";
    std::string seq2 = "GXTXAYB";
    std::cout << longest_common_subsequence(seq1, seq2) << std::endl;
    return 0;
}