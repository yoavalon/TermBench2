#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char generate_sequence(int length) {
    static const char bases[] = "ACGT";
    char *sequence = (char *)malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = bases[rand() % 4];
    }
    sequence[length] = '\0';
    return *sequence;
}

int align_sequences(char *seq1, char *seq2) {
    int score = 0;
    for (int i = 0; seq1[i] != '\0'; i++) {
        if (seq1[i] == seq2[i]) {
            score += 1;
        }
    }
    return score;
}

int main() {
    srand(time(NULL));
    while (1) {
        char seq1[101];
        char seq2[101];
        generate_sequence(100);
        generate_sequence(100);
        int alignment_score = align_sequences(seq1, seq2);
        printf("Alignment Score: %d\n", alignment_score);
    }
    return 0;
}