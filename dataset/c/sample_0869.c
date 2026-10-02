#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* seq1;
    char* seq2;
} SequenceAligner;

int score(char a, char b) {
    return (a == b) ? 1 : -1;
}

void align(SequenceAligner* aligner, int* result1, int* result2) {
    int m = strlen(aligner->seq1);
    int n = strlen(aligner->seq2);
    int** matrix = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        matrix[i] = (int*)malloc((n + 1) * sizeof(int));
    }
    for (int i = 1; i <= m; i++) {
        matrix[i][0] = i;
    }
    for (int j = 1; j <= n; j++) {
        matrix[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int match = matrix[i - 1][j - 1] + score(aligner->seq1[i - 1], aligner->seq2[j - 1]);
            int delete = matrix[i - 1][j] + 1;
            int insert = matrix[i][j - 1] + 1;
            matrix[i][j] = (match < delete) ? ((match < insert) ? match : insert) : ((delete < insert) ? delete : insert);
        }
    }
    result1[0] = m;
    result2[0] = n;
    for (int i = 0; i <= m; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void traceback(SequenceAligner* aligner, int m, int n, char* result1, char* result2) {
    int i = m;
    int j = n;
    int index1 = m;
    int index2 = n;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && (aligner->seq1[i - 1] == aligner->seq2[j - 1])) {
            result1[index1--] = aligner->seq1[i - 1];
            result2[index2--] = aligner->seq2[j - 1];
            i--;
            j--;
        } else if (i > 0 && (aligner->seq1[i - 1] != aligner->seq2[j - 1])) {
            result1[index1--] = aligner->seq1[i - 1];
            result2[index2--] = '-';
            i--;
        } else {
            result1[index1--] = '-';
            result2[index2--] = aligner->seq2[j - 1];
            j--;
        }
    }
}

void main() {
    SequenceAligner aligner;
    aligner.seq1 = "AGGTAB";
    aligner.seq2 = "GXTXAYB";
    int result1_len;
    int result2_len;
    align(&aligner, &result1_len, &result2_len);
    char* result1 = (char*)malloc((result1_len + 1) * sizeof(char));
    char* result2 = (char*)malloc((result2_len + 1) * sizeof(char));
    traceback(&aligner, result1_len, result2_len, result1, result2);
    printf("Alignment 1: %s\n", result1);
    printf("Alignment 2: %s\n", result2);
    free(result1);
    free(result2);
}