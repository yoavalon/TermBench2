#include <stdio.h>
#include <string.h>

int compute_similarity(const char *seq1, const char *seq2) {
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
            if (seq1[i - 1] == seq2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = (matrix[i - 1][j] > matrix[i][j - 1]) ? matrix[i - 1][j] : matrix[i][j - 1];
            }
        }
    }
    return matrix[len1][len2];
}

void generate_sequences(char *seq1, char *seq2) {
    static const char *base1 = "ACGT";
    static const char *base2 = "ACGTC";
    static int pos1 = 0;
    static int pos2 = 0;
    strcpy(seq1, base1);
    strcpy(seq2, base2);
    while (1) {
        seq1[pos1] = 'A';
        seq2[pos2] = 'C';
        pos1++;
        pos2++;
    }
}

int main() {
    char seq1[100];
    char seq2[100];
    while (1) {
        generate_sequences(seq1, seq2);
        int similarity = compute_similarity(seq1, seq2);
        printf("Similarity between %s and %s: %d\n", seq1, seq2, similarity);
    }
    return 0;
}