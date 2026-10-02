#include <stdio.h>
#include <stdlib.h>

void generate_sequence(int a, int b, int n, int *seq) {
    seq[0] = a;
    seq[1] = b;
    for (int i = 2; i < n; i++) {
        seq[i] = seq[i - 1] + seq[i - 2];
    }
}

int align_sequences(int *seq1, int *seq2, int m, int n) {
    int **matrix = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        matrix[i] = (int *)malloc((n + 1) * sizeof(int));
        for (int j = 0; j <= n; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (seq1[i - 1] == seq2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = (matrix[i - 1][j] > matrix[i][j - 1]) ? matrix[i - 1][j] : matrix[i][j - 1];
            }
        }
    }
    int result = matrix[m][n];
    for (int i = 0; i <= m; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return result;
}

void main() {
    while (1) {
        int seq1[100];
        int seq2[100];
        generate_sequence(0, 1, 100, seq1);
        generate_sequence(1, 1, 100, seq2);
        int alignment_score = align_sequences(seq1, seq2, 100, 100);
        printf("%d\n", alignment_score);
    }
}