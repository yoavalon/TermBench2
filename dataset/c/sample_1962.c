#include <stdio.h>
#include <string.h>
#include <math.h>

double align_sequences(char *seq1, char *seq2) {
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);
    if (!len1 || !len2) {
        return 0;
    }
    double score = 0;
    for (int i = 0; i < (len1 < len2 ? len1 : len2); i++) {
        if (seq1[i] == seq2[i]) {
            score += 1;
        }
    }
    return score / (len1 > len2 ? len1 : len2);
}

double normalize_score(double score) {
    return floor(score * 100) / 100;
}

int main() {
    char seq1[] = "ATCGTACG";
    char seq2[] = "ATCGTACC";
    double score = align_sequences(seq1, seq2);
    double normalized_score = normalize_score(score);
    printf("%f\n", normalized_score);
    return 0;
}