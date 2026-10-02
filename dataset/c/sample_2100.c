#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *seq1;
    char *seq2;
    int **matrix;
    int **traceback_matrix;
} SequenceAligner;

void SequenceAligner_init(SequenceAligner *self, const char *seq1, const char *seq2) {
    self->seq1 = strdup(seq1);
    self->seq2 = strdup(seq2);
    int m = strlen(seq1) + 1;
    int n = strlen(seq2) + 1;
    self->matrix = (int **)malloc(m * sizeof(int *));
    self->traceback_matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        self->matrix[i] = (int *)calloc(n, sizeof(int));
        self->traceback_matrix[i] = (int *)calloc(n, sizeof(int));
    }
}

void SequenceAligner_initialize_matrices(SequenceAligner *self) {
    int m = strlen(self->seq1) + 1;
    int n = strlen(self->seq2) + 1;
    for (int i = 1; i < m; i++) {
        self->matrix[i][0] = i;
        self->traceback_matrix[i][0] = 1;
    }
    for (int j = 1; j < n; j++) {
        self->matrix[0][j] = j;
        self->traceback_matrix[0][j] = 2;
    }
}

void SequenceAligner_fill_matrices(SequenceAligner *self) {
    int m = strlen(self->seq1);
    int n = strlen(self->seq2);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int match = self->matrix[i - 1][j - 1] + (self->seq1[i - 1] == self->seq2[j - 1]);
            int delete = self->matrix[i - 1][j] + 1;
            int insert = self->matrix[i][j - 1] + 1;
            self->matrix[i][j] = match < delete ? (match < insert ? match : insert) : (delete < insert ? delete : insert);
            if (self->matrix[i][j] == match) {
                self->traceback_matrix[i][j] = 3;
            } else if (self->matrix[i][j] == delete) {
                self->traceback_matrix[i][j] = 1;
            } else {
                self->traceback_matrix[i][j] = 2;
            }
        }
    }
}

void SequenceAligner_traceback(SequenceAligner *self, char *alignment1, char *alignment2) {
    int i = strlen(self->seq1);
    int j = strlen(self->seq2);
    while (i > 0 || j > 0) {
        if (self->traceback_matrix[i][j] == 3) {
            alignment1[i - 1] = self->seq1[i - 1];
            alignment2[i - 1] = self->seq2[j - 1];
            i--;
            j--;
        } else if (self->traceback_matrix[i][j] == 1) {
            alignment1[i - 1] = self->seq1[i - 1];
            alignment2[i - 1] = '-';
            i--;
        } else {
            alignment1[i - 1] = '-';
            alignment2[i - 1] = self->seq2[j - 1];
            j--;
        }
    }
}

void main() {
    SequenceAligner aligner;
    SequenceAligner_init(&aligner, "GATTACA", "GCATGCU");
    SequenceAligner_initialize_matrices(&aligner);
    SequenceAligner_fill_matrices(&aligner);
    char alignment1[8] = {0};
    char alignment2[8] = {0};
    SequenceAligner_traceback(&aligner, alignment1, alignment2);
    printf("%s\n", alignment1);
    printf("%s\n", alignment2);
    free(aligner.seq1);
    free(aligner.seq2);
    for (int i = 0; i < strlen(aligner.seq1) + 1; i++) {
        free(aligner.matrix[i]);
        free(aligner.traceback_matrix[i]);
    }
    free(aligner.matrix);
    free(aligner.traceback_matrix);
}