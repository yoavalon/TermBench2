#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int align(const std::string& seq1, const std::string& seq2, int i, int j, std::unordered_map<std::pair<int, int>, int>& memo) {
    if (memo.find({i, j}) != memo.end()) {
        return memo[{i, j}];
    }
    if (i == seq1.length() || j == seq2.length()) {
        return 0;
    }
    int match = align(seq1, seq2, i + 1, j + 1, memo) + (seq1[i] == seq2[j]);
    int deleteOp = align(seq1, seq2, i + 1, j, memo);
    int insertOp = align(seq1, seq2, i, j + 1, memo);
    int result = std::max({match, deleteOp, insertOp});
    memo[{i, j}] = result;
    return result;
}

int main() {
    std::string seq1 = "AGGTAB";
    std::string seq2 = "GXTXAYB";
    std::unordered_map<std::pair<int, int>, int> memo;
    std::cout << align(seq1, seq2, 0, 0, memo) << std::endl;
    return 0;
}