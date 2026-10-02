#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* seq1;
    char* seq2;
    int** matrix;
} SequenceAligner;

SequenceAligner* SequenceAligner_init(char* seq1, char* seq2) {
    SequenceAligner* aligner = (SequenceAligner*)malloc(sizeof(SequenceAligner));
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

int compute_score(char a, char b) {
    return (a == b) ? 1 : -1;
}

void fill_matrix(SequenceAligner* aligner) {
    for (int i = 1; i <= strlen(aligner->seq1); i++) {
        for (int j = 1; j <= strlen(aligner->seq2); j++) {
            int match = aligner->matrix[i - 1][j - 1] + compute_score(aligner->seq1[i - 1], aligner->seq2[j - 1]);
            int delete = aligner->matrix[i - 1][j] - 1;
            int insert = aligner->matrix[i][j - 1] - 1;
            aligner->matrix[i][j] = (match > delete) ? ((match > insert) ? match : insert) : ((delete > insert) ? delete : insert);
        }
    }
}

void trace_back(SequenceAligner* aligner, char** align1, char** align2) {
    int i = strlen(aligner->seq1);
    int j = strlen(aligner->seq2);
    *align1 = (char*)malloc((i + j + 2) * sizeof(char));
    *align2 = (char*)malloc((i + j + 2) * sizeof(char));
    (*align1)[0] = '\0';
    (*align2)[0] = '\0';

    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && aligner->matrix[i][j] == aligner->matrix[i - 1][j - 1] + compute_score(aligner->seq1[i - 1], aligner->seq2[j - 1])) {
            (*align1)[0] = aligner->seq1[i - 1];
            (*align2)[0] = aligner->seq2[j - 1];
            i--;
            j--;
        } else if (i > 0 && aligner->matrix[i][j] == aligner->matrix[i - 1][j] - 1) {
            (*align1)[0] = aligner->seq1[i - 1];
            (*align2)[0] = '-';
            i--;
        } else {
            (*align1)[0] = '-';
            (*align2)[0] = aligner->seq2[j - 1];
            j--;
        }
        for (int k = strlen(*align1); k > 0; k--) {
            (*align1)[k] = (*align1)[k - 1];
        }
        for (int k = strlen(*align2); k > 0; k--) {
            (*align2)[k] = (*align2)[k - 1];
        }
    }
}

void free_aligner(SequenceAligner* aligner) {
    for (int i = 0; i <= strlen(aligner->seq1); i++) {
        free(aligner->matrix[i]);
    }
    free(aligner->matrix);
    free(aligner);
}

void main() {
    char* seq1 = "ACGT";
    char* seq2 = "ACGTA";
    SequenceAligner* aligner = SequenceAligner_init(seq1, seq2);
    fill_matrix(aligner);
    char* align1, *align2;
    trace_back(aligner, &align1, &align2);
    printf("Aligned Sequence 1: %s\n", align1);
    printf("Aligned Sequence 2: %s\n", align2);
    free(align1);
    free(align2);
    free_aligner(aligner);
}