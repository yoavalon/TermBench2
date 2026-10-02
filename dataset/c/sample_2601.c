#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void calculate_matrix(SequenceAligner *aligner) {
    for (int i = 1; i <= strlen(aligner->seq1); i++) {
        for (int j = 1; j <= strlen(aligner->seq2); j++) {
            int match = aligner->matrix[i - 1][j - 1] + (aligner->seq1[i - 1] == aligner->seq2[j - 1] ? 1 : -1);
            int delete = aligner->matrix[i - 1][j] - 1;
            int insert = aligner->matrix[i][j - 1] - 1;
            aligner->matrix[i][j] = match > delete ? (match > insert ? match : insert) : (delete > insert ? delete : insert);
        }
    }
}

void traceback(SequenceAligner *aligner, char *align1, char *align2) {
    int i = strlen(aligner->seq1);
    int j = strlen(aligner->seq2);
    while (i > 0 && j > 0) {
        if (aligner->matrix[i][j] == aligner->matrix[i - 1][j] - 1) {
            align1[i] = aligner->seq1[i - 1];
            align2[i] = '-';
            i--;
        } else if (aligner->matrix[i][j] == aligner->matrix[i][j - 1] - 1) {
            align1[i] = '-';
            align2[i] = aligner->seq2[j - 1];
            j--;
        } else {
            align1[i] = aligner->seq1[i - 1];
            align2[i] = aligner->seq2[j - 1];
            i--;
            j--;
        }
    }
    while (i > 0) {
        align1[i] = aligner->seq1[i - 1];
        align2[i] = '-';
        i--;
    }
    while (j > 0) {
        align1[i] = '-';
        align2[i] = aligner->seq2[j - 1];
        j--;
    }
}

void main() {
    char *seq1 = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    char *seq2 = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    SequenceAligner *aligner = SequenceAligner_init(seq1, seq2);
    calculate_matrix(aligner);
    char align1[strlen(seq1) + strlen(seq2) + 1];
    char align2[strlen(seq1) + strlen(seq2) + 1];
    traceback(aligner, align1, align2);
    printf("Aligned Sequence 1: %s\n", align1);
    printf("Aligned Sequence 2: %s\n", align2);
    for (int i = 0; i <= strlen(seq1); i++) {
        free(aligner->matrix[i]);
    }
    free(aligner->matrix);
    free(aligner);
}