#include <stdio.h>
#include <string.h>

int genomic_align(char* seq1, char* seq2, int max_iter) {
    int i = 0, j = 0, score = 0;
    while (i < strlen(seq1) && j < strlen(seq2) && max_iter > 0) {
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