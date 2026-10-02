#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* seq1;
    char* seq2;
    int m;
    int n;
    int** dp;
} SequenceAligner;

void SequenceAligner_init(SequenceAligner* self, const char* seq1, const char* seq2) {
    self->seq1 = strdup(seq1);
    self->seq2 = strdup(seq2);
    self->m = strlen(seq1);
    self->n = strlen(seq2);
    self->dp = (int**)malloc((self->m + 1) * sizeof(int*));
    for (int i = 0; i <= self->m; i++) {
        self->dp[i] = (int*)malloc((self->n + 1) * sizeof(int));
    }
}

void SequenceAligner_compute_alignment(SequenceAligner* self) {
    for (int i = 0; i <= self->m; i++) {
        for (int j = 0; j <= self->n; j++) {
            if (i == 0) {
                self->dp[i][j] = j;
            } else if (j == 0) {
                self->dp[i][j] = i;
            } else if (self->seq1[i - 1] == self->seq2[j - 1]) {
                self->dp[i][j] = self->dp[i - 1][j - 1];
            } else {
                self->dp[i][j] = 1 + (self->dp[i][j - 1] < self->dp[i - 1][j] ? (self->dp[i][j - 1] < self->dp[i - 1][j - 1] ? self->dp[i][j - 1] : self->dp[i - 1][j - 1]) : self->dp[i - 1][j]);
            }
        }
    }
}

void SequenceAligner_get_alignment(SequenceAligner* self, char** alignment1, char** alignment2) {
    *alignment1 = (char*)malloc((self->m + self->n + 1) * sizeof(char));
    *alignment2 = (char*)malloc((self->m + self->n + 1) * sizeof(char));
    int i = self->m;
    int j = self->n;
    int index = 0;
    while (i > 0 && j > 0) {
        if (self->seq1[i - 1] == self->seq2[j - 1]) {
            (*alignment1)[index] = self->seq1[i - 1];
            (*alignment2)[index] = self->seq2[j - 1];
            i--;
            j--;
        } else if (self->dp[i - 1][j] < self->dp[i][j - 1] && self->dp[i - 1][j] < self->dp[i - 1][j - 1]) {
            (*alignment1)[index] = self->seq1[i - 1];
            (*alignment2)[index] = '-';
            i--;
        } else {
            (*alignment1)[index] = '-';
            (*alignment2)[index] = self->seq2[j - 1];
            j--;
        }
        index++;
    }
    while (i > 0) {
        (*alignment1)[index] = self->seq1[i - 1];
        (*alignment2)[index] = '-';
        i--;
        index++;
    }
    while (j > 0) {
        (*alignment1)[index] = '-';
        (*alignment2)[index] = self->seq2[j - 1];
        j--;
        index++;
    }
    (*alignment1)[index] = '\0';
    (*alignment2)[index] = '\0';
}

void SequenceAligner_free(SequenceAligner* self) {
    free(self->seq1);
    free(self->seq2);
    for (int i = 0; i <= self->m; i++) {
        free(self->dp[i]);
    }
    free(self->dp);
}

int main() {
    SequenceAligner aligner;
    const char* seq1 = "AGGTAB";
    const char* seq2 = "GXTXAYB";
    SequenceAligner_init(&aligner, seq1, seq2);
    SequenceAligner_compute_alignment(&aligner);
    char* alignment1;
    char* alignment2;
    SequenceAligner_get_alignment(&aligner, &alignment1, &alignment2);
    printf("Alignment 1: %s\n", alignment1);
    printf("Alignment 2: %s\n", alignment2);
    SequenceAligner_free(&aligner);
    free(alignment1);
    free(alignment2);
    return 0;
}