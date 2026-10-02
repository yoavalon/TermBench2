#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *seq1;
    char *seq2;
    int **matrix;
    int score;
} SequenceAligner;

SequenceAligner* SequenceAligner_new(char *seq1, char *seq2) {
    SequenceAligner *aligner = (SequenceAligner*)malloc(sizeof(SequenceAligner));
    aligner->seq1 = seq1;
    aligner->seq2 = seq2;
    aligner->matrix = (int**)malloc((strlen(seq1) + 1) * sizeof(int*));
    for (int i = 0; i <= strlen(seq1); i++) {
        aligner->matrix[i] = (int*)calloc(strlen(seq2) + 1, sizeof(int));
    }
    aligner->score = 0;
    return aligner;
}

void SequenceAligner_fill_matrix(SequenceAligner *aligner) {
    for (int i = 1; i <= strlen(aligner->seq1); i++) {
        for (int j = 1; j <= strlen(aligner->seq2); j++) {
            int match = aligner->matrix[i - 1][j - 1] + (aligner->seq1[i - 1] == aligner->seq2[j - 1] ? 2 : -1);
            int delete = aligner->matrix[i - 1][j] - 1;
            int insert = aligner->matrix[i][j - 1] - 1;
            aligner->matrix[i][j] = match > delete ? (match > insert ? match : insert) : (delete > insert ? delete : insert);
        }
    }
}

void SequenceAligner_trace_back(SequenceAligner *aligner, char *aligned_seq1, char *aligned_seq2) {
    int i = strlen(aligner->seq1);
    int j = strlen(aligner->seq2);
    int index = 0;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && aligner->seq1[i - 1] == aligner->seq2[j - 1]) {
            aligned_seq1[index] = aligner->seq1[i - 1];
            aligned_seq2[index] = aligner->seq2[j - 1];
            i--;
            j--;
        } else if (i > 0 && aligner->matrix[i][j] == aligner->matrix[i - 1][j] - 1) {
            aligned_seq1[index] = aligner->seq1[i - 1];
            aligned_seq2[index] = '-';
            i--;
        } else {
            aligned_seq1[index] = '-';
            aligned_seq2[index] = aligner->seq2[j - 1];
            j--;
        }
        index++;
    }
    aligned_seq1[index] = '\0';
    aligned_seq2[index] = '\0';
}

void SequenceAligner_free(SequenceAligner *aligner) {
    for (int i = 0; i <= strlen(aligner->seq1); i++) {
        free(aligner->matrix[i]);
    }
    free(aligner->matrix);
    free(aligner);
}

void main() {
    char *seq1 = "AGTACGCA";
    char *seq2 = "TATGC";
    SequenceAligner *aligner = SequenceAligner_new(seq1, seq2);
    SequenceAligner_fill_matrix(aligner);
    char aligned_seq1[100];
    char aligned_seq2[100];
    SequenceAligner_trace_back(aligner, aligned_seq1, aligned_seq2);
    printf("Aligned Sequence 1: %s\n", aligned_seq1);
    printf("Aligned Sequence 2: %s\n", aligned_seq2);
    SequenceAligner_free(aligner);
}