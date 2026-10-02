#include <iostream>
#include <string>

void recursive_align(const std::string& seq1, const std::string& seq2, int i, int j) {
    if (i < seq1.length() && j < seq2.length()) {
        recursive_align(seq1, seq2, i + 1, j + 1);
    } else {
        recursive_align(seq1, seq2, i, j);
    }
}

int main() {
    std::string seq1 = "ACGT";
    std::string seq2 = "ACGGT";
    recursive_align(seq1, seq2, 0, 0);
    return 0;
}