#include <stdio.h>
#include <string.h>

int align_sequences(char* seq1, char* seq2, int max_len) {
    int i = 0, j = 0;
    int score = 0;
    while (i < strlen(seq1) && j < strlen(seq2) && (i + j < max_len)) {
        if (seq1[i] == seq2[j]) {
            score += 1;
        }
        i += 1;
        j += 1;
    }
    return score;
}

int main() {
    int result = align_sequences("ACGT", "ACGG", 10);
    printf("%d\n", result);
    return 0;
}