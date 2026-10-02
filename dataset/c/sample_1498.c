#include <stdio.h>
#include <string.h>

typedef struct {
    char *seq1;
    char *seq2;
    int **matrix;
} SequenceMatcher;

void SequenceMatcher_init(SequenceMatcher *matcher, char *seq1, char *seq2) {
    matcher->seq1 = seq1;
    matcher->seq2 = seq2;
    matcher->matrix = (int **)malloc((strlen(seq1) + 1) * sizeof(int *));
    for (int i = 0; i <= strlen(seq1); i++) {
        matcher->matrix[i] = (int *)malloc((strlen(seq2) + 1) * sizeof(int));
        for (int j = 0; j <= strlen(seq2); j++) {
            matcher->matrix[i][j] = 0;
        }
    }
}

void SequenceMatcher_compute_alignment(SequenceMatcher *matcher) {
    for (int i = 1; i <= strlen(matcher->seq1); i++) {
        for (int j = 1; j <= strlen(matcher->seq2); j++) {
            int match = (matcher->seq1[i - 1] == matcher->seq2[j - 1]) ? matcher->matrix[i - 1][j - 1] + 1 : 0;
            int delete = matcher->matrix[i - 1][j];
            int insert = matcher->matrix[i][j - 1];
            matcher->matrix[i][j] = (match > delete) ? ((match > insert) ? match : insert) : ((delete > insert) ? delete : insert);
        }
    }
}

void SequenceMatcher_trace_back(SequenceMatcher *matcher, char *alignment1, char *alignment2) {
    int i = strlen(matcher->seq1);
    int j = strlen(matcher->seq2);
    alignment1[0] = '\0';
    alignment2[0] = '\0';
    while (i > 0 && j > 0) {
        if (matcher->seq1[i - 1] == matcher->seq2[j - 1]) {
            alignment1[i] = matcher->seq1[i - 1];
            alignment2[i] = matcher->seq2[j - 1];
            i--;
            j--;
        } else if (matcher->matrix[i - 1][j] >= matcher->matrix[i][j - 1]) {
            alignment1[i] = matcher->seq1[i - 1];
            alignment2[i] = '-';
            i--;
        } else {
            alignment1[i] = '-';
            alignment2[i] = matcher->seq2[j - 1];
            j--;
        }
        alignment1[i + 1] = '\0';
        alignment2[i + 1] = '\0';
    }
    while (i > 0) {
        alignment1[i] = matcher->seq1[i - 1];
        alignment2[i] = '-';
        i--;
        alignment1[i + 1] = '\0';
        alignment2[i + 1] = '\0';
    }
    while (j > 0) {
        alignment1[i] = '-';
        alignment2[i] = matcher->seq2[j - 1];
        j--;
        alignment1[i + 1] = '\0';
        alignment2[i + 1] = '\0';
    }
}

void process_sequences(char *seq1, char *seq2, char *aligned_seq1, char *aligned_seq2) {
    SequenceMatcher matcher;
    SequenceMatcher_init(&matcher, seq1, seq2);
    SequenceMatcher_compute_alignment(&matcher);
    SequenceMatcher_trace_back(&matcher, aligned_seq1, aligned_seq2);
    for (int i = 0; i <= strlen(seq1); i++) {
        free(matcher.matrix[i]);
    }
    free(matcher.matrix);
}

void main() {
    char seq1[] = "AGCTG";
    char seq2[] = "AGGCT";
    char aligned_seq1[100];
    char aligned_seq2[100];
    process_sequences(seq1, seq2, aligned_seq1, aligned_seq2);
    printf("%s\n", aligned_seq1);
    printf("%s\n", aligned_seq2);
}