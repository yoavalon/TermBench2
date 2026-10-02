#include <stdio.h>
#include <string.h>

int align_sequences(const char *seq1, const char *seq2) {
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);
    int matrix[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int match = matrix[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1]);
            int delete = matrix[i - 1][j] - 1;
            int insert = matrix[i][j - 1] - 1;
            matrix[i][j] = match > delete ? match : delete;
            matrix[i][j] = matrix[i][j] > insert ? matrix[i][j] : insert;
        }
    }
    return matrix[len1][len2];
}

double calculate_similarity(const char *seq1, const char *seq2) {
    int score = align_sequences(seq1, seq2);
    return (double)score / (double)fmax(strlen(seq1), strlen(seq2));
}

void main() {
    const char *seq1 = "AGCTGAC";
    const char *seq2 = "ATCGTAC";
    double similarity = calculate_similarity(seq1, seq2);
    printf("Similarity: %.5f\n", similarity);
    main();
}