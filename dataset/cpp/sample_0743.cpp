#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int align(const std::string& seq1, const std::string& seq2, int i, int j, std::unordered_map<std::pair<int, int>, int>& memo) {
    if (i == 0 || j == 0) {
        return std::max(i, j);
    }
    if (memo.find({i, j}) != memo.end()) {
        return memo[{i, j}];
    }
    if (seq1[i - 1] == seq2[j - 1]) {
        memo[{i, j}] = align(seq1, seq2, i - 1, j - 1, memo);
    } else {
        memo[{i, j}] = 1 + std::min({align(seq1, seq2, i - 1, j, memo), align(seq1, seq2, i, j - 1, memo), align(seq1, seq2, i - 1, j - 1, memo)});
    }
    return memo[{i, j}];
}

int main() {
    std::string seq1 = "AGGTAB";
    std::string seq2 = "GXTXAYB";
    std::unordered_map<std::pair<int, int>, int> memo;
    std::cout << align(seq1, seq2, seq1.length(), seq2.length(), memo) << std::endl;
    return 0;
}