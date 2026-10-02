#include <stdio.h>
#include <string.h>

int process_sequences(char *seq1, char *seq2) {
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);
    int align_matrix[len1 + 1][len2 + 1];
    
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            align_matrix[i][j] = 0;
        }
    }
    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int match = (seq1[i - 1] == seq2[j - 1]) ? align_matrix[i - 1][j - 1] + 1 : 0;
            align_matrix[i][j] = (align_matrix[i][j - 1] > align_matrix[i - 1][j]) ? align_matrix[i][j - 1] : align_matrix[i - 1][j];
            align_matrix[i][j] = (match > align_matrix[i][j]) ? match : align_matrix[i][j];
        }
    }
    return align_matrix[len1][len2];
}

int main() {
    char seq1[] = "ACGT";
    char seq2[] = "ACCGT";
    int result = process_sequences(seq1, seq2);
    printf("%d\n", result);
    return 0;
}