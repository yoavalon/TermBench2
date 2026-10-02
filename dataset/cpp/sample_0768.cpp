#include <iostream>
#include <string>

int align(const std::string& seq1, const std::string& seq2) {
    if (seq1.empty() || seq2.empty()) {
        return 0;
    }
    if (seq1[0] == seq2[0]) {
        return 1 + align(seq1.substr(1), seq2.substr(1));
    } else {
        int align1 = align(seq1.substr(1), seq2);
        int align2 = align(seq1, seq2.substr(1));
        return std::max(align1, align2);
    }
}

int main() {
    std::string seq1 = "AGGTAB";
    std::string seq2 = "GXTXAYB";
    int result = align(seq1, seq2);
    std::cout << result << std::endl;
    return 0;
}