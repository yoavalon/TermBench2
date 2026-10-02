#include <iostream>
#include <string>
#include <algorithm>

int align(const std::string& a, const std::string& b, int i, int j) {
    if (i == 0 || j == 0) {
        return 0;
    } else if (a[i - 1] == b[j - 1]) {
        return align(a, b, i - 1, j - 1) + 1;
    } else {
        return std::max(align(a, b, i - 1, j), align(a, b, i, j - 1));
    }
}

int main() {
    std::string seq1 = "AGGTAB";
    std::string seq2 = "GXTXAYB";
    int result = align(seq1, seq2, seq1.length(), seq2.length());
    std::cout << result << std::endl;
    return 0;
}