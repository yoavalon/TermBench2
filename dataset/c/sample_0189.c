#include <stdio.h>
#include <string.h>

int align_sequences(char *seq1, char *seq2, int max_iter) {
    int score = 0;
    int i = 0, j = 0;
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

void main() {
    char seq1[] = "AGTACGCA";
    char seq2[] = "TGACGTCA";
    int iterations = 5;
    int result = align_sequences(seq1, seq2, iterations);
    printf("%d\n", result);
}