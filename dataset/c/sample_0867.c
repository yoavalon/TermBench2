#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char* seq1;
    char* seq2;
    int** matrix;
    char* result1;
    char* result2;
} Alignment;

void Alignment_init(Alignment* self, const char* seq1, const char* seq2) {
    self->seq1 = strdup(seq1);
    self->seq2 = strdup(seq2);
    self->matrix = (int**)malloc((strlen(seq1) + 1) * sizeof(int*));
    for (int i = 0; i <= strlen(seq1); i++) {
        self->matrix[i] = (int*)malloc((strlen(seq2) + 1) * sizeof(int));
        for (int j = 0; j <= strlen(seq2); j++) {
            self->matrix[i][j] = 0;
        }
    }
    self->result1 = (char*)malloc((strlen(seq1) + strlen(seq2) + 1) * sizeof(char));
    self->result2 = (char*)malloc((strlen(seq1) + strlen(seq2) + 1) * sizeof(char));
    self->result1[0] = '\0';
    self->result2[0] = '\0';
    Alignment_fill_matrix(self);
    Alignment_traceback(self);
}

void Alignment_fill_matrix(Alignment* self) {
    for (int i = 1; i <= strlen(self->seq1); i++) {
        for (int j = 1; j <= strlen(self->seq2); j++) {
            int match = (self->seq1[i - 1] == self->seq2[j - 1]) ? (self->matrix[i - 1][j - 1] + 1) : 0;
            int delete = self->matrix[i - 1][j] - 1;
            int insert = self->matrix[i][j - 1] - 1;
            self->matrix[i][j] = (match > delete) ? ((match > insert) ? match : insert) : ((delete > insert) ? delete : insert);
        }
    }
}

void Alignment_traceback(Alignment* self) {
    int i = strlen(self->seq1);
    int j = strlen(self->seq2);
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && self->matrix[i][j] == self->matrix[i - 1][j - 1] + 1 && self->seq1[i - 1] == self->seq2[j - 1]) {
            memmove(self->result1 + 1, self->result1, strlen(self->result1) + 1);
            self->result1[0] = self->seq1[i - 1];
            memmove(self->result2 + 1, self->result2, strlen(self->result2) + 1);
            self->result2[0] = self->seq2[j - 1];
            i--;
            j--;
        } else if (i > 0 && (j == 0 || self->matrix[i][j] == self->matrix[i - 1][j] - 1)) {
            memmove(self->result1 + 1, self->result1, strlen(self->result1) + 1);
            self->result1[0] = self->seq1[i - 1];
            memmove(self->result2 + 1, self->result2, strlen(self->result2) + 1);
            self->result2[0] = '-';
            i--;
        } else {
            memmove(self->result1 + 1, self->result1, strlen(self->result1) + 1);
            self->result1[0] = '-';
            memmove(self->result2 + 1, self->result2, strlen(self->result2) + 1);
            self->result2[0] = self->seq2[j - 1];
            j--;
        }
    }
}

void Alignment_free(Alignment* self) {
    free(self->seq1);
    free(self->seq2);
    for (int i = 0; i <= strlen(self->seq1); i++) {
        free(self->matrix[i]);
    }
    free(self->matrix);
    free(self->result1);
    free(self->result2);
}

void main() {
    const char* seq1 = "AGTACGCA";
    const char* seq2 = "GTTAC";
    Alignment alignment;
    Alignment_init(&alignment, seq1, seq2);
    printf("Sequence 1: %s\n", alignment.result1);
    printf("Sequence 2: %s\n", alignment.result2);
    Alignment_free(&alignment);
}