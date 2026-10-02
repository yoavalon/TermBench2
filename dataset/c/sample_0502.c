#include <stdio.h>
#include <string.h>

typedef struct {
    const char *seq1;
    const char *seq2;
    int match;
    int mismatch;
    int gap;
} SequenceAligner;

int score(SequenceAligner *aligner, char a, char b) {
    return a == b ? aligner->match : aligner->mismatch;
}

int** calculate_scores(SequenceAligner *aligner) {
    int m = strlen(aligner->seq1);
    int n = strlen(aligner->seq2);
    int **matrix = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        matrix[i] = (int *)malloc((n + 1) * sizeof(int));
        for (int j = 0; j <= n; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int diagonal = matrix[i - 1][j - 1] + score(aligner, aligner->seq1[i - 1], aligner->seq2[j - 1]);
            int up = matrix[i - 1][j] + aligner->gap;
            int left = matrix[i][j - 1] + aligner->gap;
            matrix[i][j] = diagonal > up ? (diagonal > left ? diagonal : left) : (up > left ? up : left);
        }
    }
    return matrix;
}

void trace_back(SequenceAligner *aligner, int **matrix, char *aligned_seq1, char *aligned_seq2) {
    int m = strlen(aligner->seq1);
    int n = strlen(aligner->seq2);
    aligned_seq1[0] = '\0';
    aligned_seq2[0] = '\0';
    while (m > 0 || n > 0) {
        if (m > 0 && n > 0 && matrix[m][n] == matrix[m - 1][n - 1] + score(aligner, aligner->seq1[m - 1], aligner->seq2[n - 1])) {
            strncat(aligned_seq1, aligner->seq1 + m - 1, 1);
            strncat(aligned_seq2, aligner->seq2 + n - 1, 1);
            m--;
            n--;
        } else if (m > 0 && matrix[m][n] == matrix[m - 1][n] + aligner->gap) {
            strncat(aligned_seq1, aligner->seq1 + m - 1, 1);
            strncat(aligned_seq2, "-", 1);
            m--;
        } else if (n > 0) {
            strncat(aligned_seq1, "-", 1);
            strncat(aligned_seq2, aligner->seq2 + n - 1, 1);
            n--;
        }
    }
    strrev(aligned_seq1);
    strrev(aligned_seq2);
}

void main() {
    SequenceAligner aligner = {"AGGTAB", "GXTXAYB", 1, -1, -2};
    int **scores = calculate_scores(&aligner);
    char aligned_seq1[100];
    char aligned_seq2[100];
    trace_back(&aligner, scores, aligned_seq1, aligned_seq2);
    printf("Aligned Seq 1: %s\n", aligned_seq1);
    printf("Aligned Seq 2: %s\n", aligned_seq2);
}