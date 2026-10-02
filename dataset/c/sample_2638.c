#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* seq1;
    char* seq2;
    int** matrix;
} SequenceAligner;

void SequenceAligner_init(SequenceAligner* self, const char* seq1, const char* seq2) {
    self->seq1 = strdup(seq1);
    self->seq2 = strdup(seq2);
    self->matrix = (int**)malloc((strlen(seq1) + 1) * sizeof(int*));
    for (int i = 0; i <= strlen(seq1); i++) {
        self->matrix[i] = (int*)calloc(strlen(seq2) + 1, sizeof(int));
    }
}

void SequenceAligner_fill_matrix(SequenceAligner* self) {
    for (int i = 1; i <= strlen(self->seq1); i++) {
        for (int j = 1; j <= strlen(self->seq2); j++) {
            int match = (self->seq1[i - 1] == self->seq2[j - 1]) ? self->matrix[i - 1][j - 1] + 1 : 0;
            self->matrix[i][j] = (self->matrix[i - 1][j] > self->matrix[i][j - 1]) ? 
                                 (self->matrix[i - 1][j] > match ? self->matrix[i - 1][j] : match) : 
                                 (self->matrix[i][j - 1] > match ? self->matrix[i][j - 1] : match);
        }
    }
}

void SequenceAligner_traceback(SequenceAligner* self, char** aligned_seq1, char** aligned_seq2) {
    int i = strlen(self->seq1);
    int j = strlen(self->seq2);
    int index = 0;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && self->seq1[i - 1] == self->seq2[j - 1]) {
            aligned_seq1[0][index] = self->seq1[i - 1];
            aligned_seq2[0][index] = self->seq2[j - 1];
            i--;
            j--;
        } else if (i > 0 && self->matrix[i][j] == self->matrix[i - 1][j]) {
            aligned_seq1[0][index] = self->seq1[i - 1];
            aligned_seq2[0][index] = '-';
            i--;
        } else {
            aligned_seq1[0][index] = '-';
            aligned_seq2[0][index] = self->seq2[j - 1];
            j--;
        }
        index++;
    }
    aligned_seq1[0][index] = '\0';
    aligned_seq2[0][index] = '\0';
    strrev(aligned_seq1[0]);
    strrev(aligned_seq2[0]);
}

void SequenceAligner_free(SequenceAligner* self) {
    free(self->seq1);
    free(self->seq2);
    for (int i = 0; i <= strlen(self->seq1); i++) {
        free(self->matrix[i]);
    }
    free(self->matrix);
}

void main() {
    SequenceAligner aligner;
    const char* seq1 = "AGGTAB";
    const char* seq2 = "GXTXAYB";
    SequenceAligner_init(&aligner, seq1, seq2);
    SequenceAligner_fill_matrix(&aligner);
    char* aligned_seq1 = (char*)malloc(100 * sizeof(char));
    char* aligned_seq2 = (char*)malloc(100 * sizeof(char));
    SequenceAligner_traceback(&aligner, &aligned_seq1, &aligned_seq2);
    printf("%s\n", aligned_seq1);
    printf("%s\n", aligned_seq2);
    SequenceAligner_free(&aligner);
    free(aligned_seq1);
    free(aligned_seq2);
}