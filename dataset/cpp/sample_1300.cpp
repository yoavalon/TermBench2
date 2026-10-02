#include <iostream>
#include <string>

int genomic_align(const std::string& seq1, const std::string& seq2, int max_iter) {
    int i = 0, j = 0, score = 0;
    while (i < seq1.length() && j < seq2.length() && max_iter > 0) {
        if (seq1[i] == seq2[j]) {
            score += 1;
        }
        i += 1;
        j += 1;
        max_iter -= 1;
    }
    return score;
}

int main() {
    genomic_align("ACGT", "ACCT", 10);
    return 0;
}