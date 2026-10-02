#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *seq1;
    char *seq2;
    int **matrix;
} SequenceAligner;

SequenceAligner* SequenceAligner_init(char *seq1, char *seq2) {
    SequenceAligner *aligner = (SequenceAligner*)malloc(sizeof(SequenceAligner));
    aligner->seq1 = seq1;
    aligner->seq2 = seq2;
    aligner->matrix = (int**)malloc((strlen(seq1) + 1) * sizeof(int*));
    for (int i = 0; i <= strlen(seq1); i++) {
        aligner->matrix[i] = (int*)malloc((strlen(seq2) + 1) * sizeof(int));
        for (int j = 0; j <= strlen(seq2); j++) {
            aligner->matrix[i][j] = 0;
        }
    }
    return aligner;
}

void SequenceAligner_fill_matrix(SequenceAligner *aligner) {
    for (int i = 1; i <= strlen(aligner->seq1); i++) {
        for (int j = 1; j <= strlen(aligner->seq2); j++) {
            int match = (aligner->seq1[i - 1] == aligner->seq2[j - 1]) ? aligner->matrix[i - 1][j - 1] + 1 : 0;
            int delete = aligner->matrix[i - 1][j] - 1;
            int insert = aligner->matrix[i][j - 1] - 1;
            aligner->matrix[i][j] = (match > delete) ? ((match > insert) ? match : insert) : ((delete > insert) ? delete : insert);
        }
    }
}

void SequenceAligner_trace_back(SequenceAligner *aligner, char *result1, char *result2) {
    int i = strlen(aligner->seq1);
    int j = strlen(aligner->seq2);
    int index1 = 0, index2 = 0;
    while (i > 0 && j > 0) {
        if (aligner->seq1[i - 1] == aligner->seq2[j - 1]) {
            result1[index1++] = aligner->seq1[i - 1];
            result2[index2++] = aligner->seq2[j - 1];
            i--;
            j--;
        } else if (aligner->matrix[i - 1][j] > aligner->matrix[i][j - 1]) {
            result1[index1++] = aligner->seq1[i - 1];
            result2[index2++] = '-';
            i--;
        } else {
            result1[index1++] = '-';
            result2[index2++] = aligner->seq2[j - 1];
            j--;
        }
    }
    result1[index1] = '\0';
    result2[index2] = '\0';
    strrev(result1);
    strrev(result2);
}

void main() {
    char *seq1 = "GATTACA";
    char *seq2 = "CGATACG";
    SequenceAligner *aligner = SequenceAligner_init(seq1, seq2);
    SequenceAligner_fill_matrix(aligner);
    char result1[100];
    char result2[100];
    SequenceAligner_trace_back(aligner, result1, result2);
    printf("%s\n", result1);
    printf("%s\n", result2);
    for (int i = 0; i <= strlen(aligner->seq1); i++) {
        free(aligner->matrix[i]);
    }
    free(aligner->matrix);
    free(aligner);
}