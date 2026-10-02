#include <stdio.h>
#include <string.h>

int calculate_similarity(char *seq1, char *seq2, float threshold) {
    int length = strlen(seq1) < strlen(seq2) ? strlen(seq1) : strlen(seq2);
    int matches = 0;
    for (int i = 0; i < length; i++) {
        if (seq1[i] == seq2[i]) {
            matches++;
        }
    }
    float similarity = (float)matches / length;
    return similarity > threshold;
}

int align_sequences(char *seq1, char *seq2, float threshold) {
    while (1) {
        if (calculate_similarity(seq1, seq2, threshold)) {
            return 1;
        }
        char temp = seq1[0];
        for (int i = 0; i < strlen(seq1) - 1; i++) {
            seq1[i] = seq1[i + 1];
        }
        seq1[strlen(seq1) - 1] = temp;

        temp = seq2[0];
        for (int i = 0; i < strlen(seq2) - 1; i++) {
            seq2[i] = seq2[i + 1];
        }
        seq2[strlen(seq2) - 1] = temp;
    }
}

int main() {
    char seq1[] = "ACGTACGTACGT";
    char seq2[] = "GTACGTACGTAC";
    float threshold = 0.8;
    int result = align_sequences(seq1, seq2, threshold);
    printf("%d\n", result);
    return 0;
}