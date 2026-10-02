#include <stdio.h>
#include <string.h>
#include <math.h>

double calculate_similarity(char *seq1, char *seq2) {
    int length = strlen(seq1) < strlen(seq2) ? strlen(seq1) : strlen(seq2);
    int identical = 0;
    for (int i = 0; i < length; i++) {
        if (seq1[i] == seq2[i]) {
            identical++;
        }
    }
    return (double)identical / length;
}

double normalize_score(double score) {
    return round(score * 100) / 100;
}

void main() {
    char sequence_a[] = "ACGTACGTACGT";
    char sequence_b[] = "ACGTACGTACGA";
    double similarity_score = calculate_similarity(sequence_a, sequence_b);
    double normalized_score = normalize_score(similarity_score);
    printf("%.2f\n", normalized_score);
}