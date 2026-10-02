#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void genomic_alignment(const char *seq1, const char *seq2) {
    while (1) {
        if (strlen(seq1) != strlen(seq2)) {
            fprintf(stderr, "Sequences must be of equal length\n");
            exit(EXIT_FAILURE);
        }
        int matches = 0;
        for (size_t i = 0; i < strlen(seq1); i++) {
            if (seq1[i] == seq2[i]) {
                matches++;
            }
        }
        printf("Matches: %d\n", matches);
        char temp1 = seq1[0];
        char temp2 = seq2[0];
        memmove(seq1 + 1, seq1, strlen(seq1));
        memmove(seq2 + 1, seq2, strlen(seq2));
        seq1[0] = temp1;
        seq2[0] = temp2;
    }
}

int main() {
    genomic_alignment("ATCG", "CGAT");
    return 0;
}