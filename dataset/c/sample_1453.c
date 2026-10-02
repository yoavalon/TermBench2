#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *seq1;
    char *seq2;
    int **matrix;
    int **traceback;
} SequenceAligner;

void SequenceAligner_init(SequenceAligner *aligner, const char *seq1, const char *seq2) {
    aligner->seq1 = (char *)seq1;
    aligner->seq2 = (char *)seq2;
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);
    aligner->matrix = (int **)malloc((len1 + 1) * sizeof(int *));
    aligner->traceback = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        aligner->matrix[i] = (int *)calloc(len2 + 1, sizeof(int));
        aligner->traceback[i] = (int *)calloc(len2 + 1, sizeof(int));
    }
}

void SequenceAligner_fill_matrix(SequenceAligner *aligner) {
    int len1 = strlen(aligner->seq1);
    int len2 = strlen(aligner->seq2);
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int match = aligner->matrix[i - 1][j - 1] + (aligner->seq1[i - 1] == aligner->seq2[j - 1]);
            int delete = aligner->matrix[i - 1][j] - 1;
            int insert = aligner->matrix[i][j - 1] - 1;
            aligner->matrix[i][j] = (match > delete) ? ((match > insert) ? match : insert) : ((delete > insert) ? delete : insert);
            if (aligner->matrix[i][j] == match) {
                aligner->traceback[i][j] = 1;
            } else if (aligner->matrix[i][j] == delete) {
                aligner->traceback[i][j] = 2;
            } else {
                aligner->traceback[i][j] = 3;
            }
        }
    }
}

void SequenceAligner_align_sequences(SequenceAligner *aligner, char *aligned_seq1, char *aligned_seq2) {
    int len1 = strlen(aligner->seq1);
    int len2 = strlen(aligner->seq2);
    int i = len1, j = len2;
    int index1 = 0, index2 = 0;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && aligner->traceback[i][j] == 1) {
            aligned_seq1[index1++] = aligner->seq1[i - 1];
            aligned_seq2[index2++] = aligner->seq2[j - 1];
            i--;
            j--;
        } else if (i > 0 && (j == 0 || aligner->traceback[i][j] == 2)) {
            aligned_seq1[index1++] = aligner->seq1[i - 1];
            aligned_seq2[index2++] = '-';
            i--;
        } else {
            aligned_seq1[index1++] = '-';
            aligned_seq2[index2++] = aligner->seq2[j - 1];
            j--;
        }
    }
    aligned_seq1[index1] = '\0';
    aligned_seq2[index2] = '\0';
}

void SequenceAligner_free(SequenceAligner *aligner) {
    int len1 = strlen(aligner->seq1);
    for (int i = 0; i <= len1; i++) {
        free(aligner->matrix[i]);
        free(aligner->traceback[i]);
    }
    free(aligner->matrix);
    free(aligner->traceback);
}

void main() {
    const char *seq1 = "GATTACA";
    const char *seq2 = "CGATTACG";
    SequenceAligner aligner;
    SequenceAligner_init(&aligner, seq1, seq2);
    SequenceAligner_fill_matrix(&aligner);
    char aligned_seq1[100], aligned_seq2[100];
    SequenceAligner_align_sequences(&aligner, aligned_seq1, aligned_seq2);
    printf("%s\n", aligned_seq1);
    printf("%s\n", aligned_seq2);
    SequenceAligner_free(&aligner);
}