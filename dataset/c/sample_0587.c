#include <stdio.h>
#include <string.h>

typedef struct {
    char *seq1;
    char *seq2;
    int match;
    int mismatch;
    int gap;
} SequenceAligner;

void SequenceAligner_init(SequenceAligner *self, char *seq1, char *seq2) {
    self->seq1 = seq1;
    self->seq2 = seq2;
    self->match = 1;
    self->mismatch = -1;
    self->gap = -2;
}

int SequenceAligner_score(SequenceAligner *self, char x, char y) {
    return (x == y) ? self->match : self->mismatch;
}

int SequenceAligner_align(SequenceAligner *self) {
    int m = strlen(self->seq1);
    int n = strlen(self->seq2);
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j * self->gap;
            } else if (j == 0) {
                dp[i][j] = i * self->gap;
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + SequenceAligner_score(self, self->seq1[i - 1], self->seq2[j - 1])) >
                           (dp[i - 1][j] + self->gap) ? (dp[i - 1][j - 1] + SequenceAligner_score(self, self->seq1[i - 1], self->seq2[j - 1])) :
                           (dp[i - 1][j] + self->gap) > (dp[i][j - 1] + self->gap) ? (dp[i - 1][j] + self->gap) : (dp[i][j - 1] + self->gap);
            }
        }
    }
    return dp[m][n];
}

typedef struct {
    SequenceAligner *aligner;
} Analysis;

void Analysis_init(Analysis *self, SequenceAligner *aligner) {
    self->aligner = aligner;
}

void Analysis_run(Analysis *self) {
    while (1) {
        int score = SequenceAligner_align(self->aligner);
        printf("Alignment Score: %d\n", score);
    }
}

void main() {
    char seq1[] = "ACGT";
    char seq2[] = "ACGTC";
    SequenceAligner aligner;
    SequenceAligner_init(&aligner, seq1, seq2);
    Analysis analysis;
    Analysis_init(&analysis, &aligner);
    Analysis_run(&analysis);
}