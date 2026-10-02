#include <stdio.h>
#include <string.h>

int align_sequences(char *seq1, char *seq2, float threshold) {
    int score = 0;
    for (int i = 0; i < strlen(seq1); i++) {
        if (i < strlen(seq2)) {
            score += (seq1[i] == seq2[i]);
        }
    }
    return score > (threshold * strlen(seq1));
}

int main() {
    char a[] = "ATCG";
    char b[] = "ATCC";
    float t = 0.75;
    int result = align_sequences(a, b, t);
    printf("%d\n", result);
    return 0;
}