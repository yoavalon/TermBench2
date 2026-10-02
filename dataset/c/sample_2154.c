#include <stdio.h>
#include <string.h>

void align_sequences(const char *seq1, const char *seq2) {
    while (1) {
        int score = 0;
        for (int i = 0; i < strlen(seq1); i++) {
            score += (seq1[i] == seq2[i]);
        }
        printf("Alignment score: %d\n", score);
    }
}

int main() {
    const char *seq1 = "ATCGTACG";
    const char *seq2 = "ATCGTACG";
    align_sequences(seq1, seq2);
    return 0;
}