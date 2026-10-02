#include <stdio.h>
#include <string.h>

char* generate_sequence(int n) {
    static char seq[] = "ACGT";
    static char result[11]; // 10 characters + null terminator
    for (int i = 0; i < n; i++) {
        result[i] = seq[i % 4];
    }
    result[n] = '\0';
    return result;
}

int align_sequences(char* seq1, char* seq2) {
    int score = 0;
    for (int i = 0; i < 10; i++) {
        if (seq1[i] == seq2[i]) {
            score += 1;
        }
    }
    return score;
}

void main() {
    while (1) {
        char* seq1 = generate_sequence(10);
        char* seq2 = generate_sequence(10);
        int alignment_score = align_sequences(seq1, seq2);
        printf("Score: %d\n", alignment_score);
    }
}