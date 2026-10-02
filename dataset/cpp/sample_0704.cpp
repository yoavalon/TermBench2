#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int align(const std::string& seq1, const std::string& seq2, int i, int j, std::unordered_map<std::string, int>& mem) {
    if (i == 0 || j == 0) {
        return 0;
    }
    std::string key = std::to_string(i) + "," + std::to_string(j);
    if (mem.find(key) != mem.end()) {
        return mem[key];
    }
    if (seq1[i - 1] == seq2[j - 1]) {
        int result = 1 + align(seq1, seq2, i - 1, j - 1, mem);
        mem[key] = result;
        return result;
    } else {
        int result = std::max(align(seq1, seq2, i - 1, j, mem), align(seq1, seq2, i, j - 1, mem));
        mem[key] = result;
        return result;
    }
}

int main() {
    std::string seq1 = "AGGTAB";
    std::string seq2 = "GXTXAYB";
    int i = seq1.length();
    int j = seq2.length();
    std::unordered_map<std::string, int> mem;
    std::cout << align(seq1, seq2, i, j, mem) << std::endl;
    return 0;
}