#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *seq1;
    char *seq2;
    int **matrix;
} GenomicAligner;

void GenomicAligner_init(GenomicAligner *self, const char *seq1, const char *seq2) {
    self->seq1 = strdup(seq1);
    self->seq2 = strdup(seq2);
    self->matrix = (int **)malloc((strlen(seq1) + 1) * sizeof(int *));
    for (int i = 0; i <= strlen(seq1); i++) {
        self->matrix[i] = (int *)calloc(strlen(seq2) + 1, sizeof(int));
    }
}

void GenomicAligner__fill_matrix(GenomicAligner *self) {
    for (int i = 1; i <= strlen(self->seq1); i++) {
        for (int j = 1; j <= strlen(self->seq2); j++) {
            if (self->seq1[i - 1] == self->seq2[j - 1]) {
                self->matrix[i][j] = self->matrix[i - 1][j - 1] + 1;
            } else {
                self->matrix[i][j] = self->matrix[i - 1][j] > self->matrix[i][j - 1] ? self->matrix[i - 1][j] : self->matrix[i][j - 1];
            }
        }
    }
}

void GenomicAligner__traceback(GenomicAligner *self, char *alignment1, char *alignment2) {
    int i = strlen(self->seq1);
    int j = strlen(self->seq2);
    int pos1 = 0, pos2 = 0;
    while (i > 0 && j > 0) {
        if (self->seq1[i - 1] == self->seq2[j - 1]) {
            alignment1[pos1++] = self->seq1[i - 1];
            alignment2[pos2++] = self->seq2[j - 1];
            i--;
            j--;
        } else if (self->matrix[i - 1][j] > self->matrix[i][j - 1]) {
            alignment1[pos1++] = self->seq1[i - 1];
            alignment2[pos2++] = '-';
            i--;
        } else {
            alignment1[pos1++] = '-';
            alignment2[pos2++] = self->seq2[j - 1];
            j--;
        }
    }
    while (pos1 > 0) {
        alignment1[pos1] = alignment1[pos1 - 1];
        alignment2[pos2] = alignment2[pos2 - 1];
        pos1--;
        pos2--;
    }
    alignment1[pos1] = '\0';
    alignment2[pos2] = '\0';
}

void GenomicAligner_align(GenomicAligner *self, char *alignment1, char *alignment2) {
    GenomicAligner__fill_matrix(self);
    GenomicAligner__traceback(self, alignment1, alignment2);
}

void GenomicAligner_free(GenomicAligner *self) {
    free(self->seq1);
    free(self->seq2);
    for (int i = 0; i <= strlen(self->seq1); i++) {
        free(self->matrix[i]);
    }
    free(self->matrix);
}

void main() {
    const char *seq1 = "AGTACGCA";
    const char *seq2 = "TGACGTCA";
    GenomicAligner aligner;
    GenomicAligner_init(&aligner, seq1, seq2);
    char alignment1[100];
    char alignment2[100];
    GenomicAligner_align(&aligner, alignment1, alignment2);
    printf("Alignment 1: %s\n", alignment1);
    printf("Alignment 2: %s\n", alignment2);
    GenomicAligner_free(&aligner);
}