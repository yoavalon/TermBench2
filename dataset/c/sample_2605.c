#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *seq1;
    char *seq2;
    int len1;
    int len2;
} SequenceMatcher;

void SequenceMatcher_init(SequenceMatcher *self, char *seq1, char *seq2) {
    self->seq1 = seq1;
    self->seq2 = seq2;
    self->len1 = strlen(seq1);
    self->len2 = strlen(seq2);
}

int SequenceMatcher_match(SequenceMatcher *self) {
    int **matrix = (int **)malloc((self->len1 + 1) * sizeof(int *));
    for (int i = 0; i <= self->len1; i++) {
        matrix[i] = (int *)malloc((self->len2 + 1) * sizeof(int));
        for (int j = 0; j <= self->len2; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 1; i <= self->len1; i++) {
        for (int j = 1; j <= self->len2; j++) {
            if (self->seq1[i - 1] == self->seq2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = (matrix[i - 1][j] > matrix[i][j - 1]) ? matrix[i - 1][j] : matrix[i][j - 1];
            }
        }
    }

    int result = matrix[self->len1][self->len2];

    for (int i = 0; i <= self->len1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return result;
}

typedef struct {
    char **sequences;
    int num_sequences;
} GenomicSequenceAnalyzer;

void GenomicSequenceAnalyzer_init(GenomicSequenceAnalyzer *self, char **sequences, int num_sequences) {
    self->sequences = sequences;
    self->num_sequences = num_sequences;
}

void GenomicSequenceAnalyzer_analyze(GenomicSequenceAnalyzer *self, int *results) {
    for (int i = 0; i < self->num_sequences; i++) {
        for (int j = i + 1; j < self->num_sequences; j++) {
            SequenceMatcher matcher;
            SequenceMatcher_init(&matcher, self->sequences[i], self->sequences[j]);
            int score = SequenceMatcher_match(&matcher);
            results[3 * ((i * self->num_sequences) + j)] = i;
            results[3 * ((i * self->num_sequences) + j) + 1] = j;
            results[3 * ((i * self->num_sequences) + j) + 2] = score;
        }
    }
}

void main() {
    char *sequences[] = {"ATCGTACG", "CGTACGTA", "GTAATCGC", "TACGTACG", "ACGTACGT"};
    int num_sequences = sizeof(sequences) / sizeof(sequences[0]);

    int results[3 * (num_sequences * (num_sequences - 1) / 2)];

    GenomicSequenceAnalyzer analyzer;
    GenomicSequenceAnalyzer_init(&analyzer, sequences, num_sequences);
    GenomicSequenceAnalyzer_analyze(&analyzer, results);

    for (int i = 0; i < num_sequences * (num_sequences - 1) / 2; i++) {
        printf("Sequence %d vs Sequence %d: Alignment Score %d\n", results[3 * i], results[3 * i + 1], results[3 * i + 2]);
    }
}