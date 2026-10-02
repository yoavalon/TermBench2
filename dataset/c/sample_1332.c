#include <stdio.h>
#include <string.h>

int align_sequences(char *seq1, char *seq2) {
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);
    int matrix[len1 + 1][len2 + 1];
    
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (seq1[i - 1] == seq2[j - 1]) ? 0 : 1;
            matrix[i][j] = (matrix[i - 1][j] + 1 < matrix[i][j - 1] + 1) ? matrix[i - 1][j] + 1 : matrix[i][j - 1] + 1;
            matrix[i][j] = (matrix[i][j] < matrix[i - 1][j - 1] + cost) ? matrix[i][j] : matrix[i - 1][j - 1] + cost;
        }
    }
    return matrix[len1][len2];
}

int main() {
    char sequence1[] = "AGCTG";
    char sequence2[] = "AGGCT";
    int distance = align_sequences(sequence1, sequence2);
    printf("Edit distance: %d\n", distance);
    return 0;
}