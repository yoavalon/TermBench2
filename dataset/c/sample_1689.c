#include <stdio.h>
#include <string.h>

void mutate_sequence(char *seq, char *mutations, int len) {
    for (int i = 0; i < len; i++) {
        if (0 <= i && i < len) {
            seq[i] = mutations[i];
        }
    }
}

int align_sequences(char *seq1, char *seq2, char *mutations, int len) {
    mutate_sequence(seq1, mutations, len);
    int score = 0;
    for (int i = 0; i < len; i++) {
        if (seq1[i] == seq2[i]) {
            score++;
        }
    }
    return score;
}

int main() {
    char seq1[] = {'A', 'T', 'C', 'G', 'A'};
    char seq2[] = {'A', 'C', 'C', 'G', 'T'};
    char mutations[] = {'C', 'G', 'T', 'A', 'G'};
    int len = sizeof(seq1) / sizeof(seq1[0]);
    while (1) {
        int score = align_sequences(seq1, seq2, mutations, len);
        printf("%d\n", score);
    }
    return 0;
}