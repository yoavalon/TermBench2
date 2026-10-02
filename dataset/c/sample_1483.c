#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *seq1;
    char *seq2;
    int **score_matrix;
    int **traceback_matrix;
    int max_score;
    int max_position[2];
} SequenceAligner;

void SequenceAligner_init(SequenceAligner *aligner, const char *seq1, const char *seq2) {
    aligner->seq1 = strdup(seq1);
    aligner->seq2 = strdup(seq2);
    aligner->max_score = 0;
    aligner->max_position[0] = 0;
    aligner->max_position[1] = 0;

    int len1 = strlen(seq1);
    int len2 = strlen(seq2);
    aligner->score_matrix = (int **)malloc((len1 + 1) * sizeof(int *));
    aligner->traceback_matrix = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        aligner->score_matrix[i] = (int *)calloc((len2 + 1), sizeof(int));
        aligner->traceback_matrix[i] = (int *)calloc((len2 + 1), sizeof(int));
    }
}

void SequenceAligner_initialize_matrices(SequenceAligner *aligner) {
    int len1 = strlen(aligner->seq1);
    int len2 = strlen(aligner->seq2);
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            aligner->score_matrix[i][j] = 0;
            aligner->traceback_matrix[i][j] = 0;
        }
    }
}

void SequenceAligner_fill_matrices(SequenceAligner *aligner) {
    int len1 = strlen(aligner->seq1);
    int len2 = strlen(aligner->seq2);
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int match = aligner->score_matrix[i - 1][j - 1] + (aligner->seq1[i - 1] == aligner->seq2[j - 1] ? 1 : -1);
            int delete = aligner->score_matrix[i - 1][j] - 1;
            int insert = aligner->score_matrix[i][j - 1] - 1;
            aligner->score_matrix[i][j] = match > delete ? match : delete;
            aligner->score_matrix[i][j] = aligner->score_matrix[i][j] > insert ? aligner->score_matrix[i][j] : insert;
            if (aligner->score_matrix[i][j] == match) {
                aligner->traceback_matrix[i][j] = 1;
            } else if (aligner->score_matrix[i][j] == delete) {
                aligner->traceback_matrix[i][j] = 2;
            } else {
                aligner->traceback_matrix[i][j] = 3;
            }
            if (aligner->score_matrix[i][j] > aligner->max_score) {
                aligner->max_score = aligner->score_matrix[i][j];
                aligner->max_position[0] = i;
                aligner->max_position[1] = j;
            }
        }
    }
}

void SequenceAligner_backtrack(SequenceAligner *aligner, char *aligned_seq1, char *aligned_seq2) {
    int i = aligner->max_position[0];
    int j = aligner->max_position[1];
    int pos1 = 0, pos2 = 0;
    while (i > 0 && j > 0) {
        if (aligner->traceback_matrix[i][j] == 1) {
            aligned_seq1[pos1++] = aligner->seq1[i - 1];
            aligned_seq2[pos2++] = aligner->seq2[j - 1];
            i--;
            j--;
        } else if (aligner->traceback_matrix[i][j] == 2) {
            aligned_seq1[pos1++] = aligner->seq1[i - 1];
            aligned_seq2[pos2++] = '-';
            i--;
        } else {
            aligned_seq1[pos1++] = '-';
            aligned_seq2[pos2++] = aligner->seq2[j - 1];
            j--;
        }
    }
    aligned_seq1[pos1] = '\0';
    aligned_seq2[pos2] = '\0';
    for (int k = 0; k < pos1 / 2; k++) {
        char temp = aligned_seq1[k];
        aligned_seq1[k] = aligned_seq1[pos1 - k - 1];
        aligned_seq1[pos1 - k - 1] = temp;
    }
    for (int k = 0; k < pos2 / 2; k++) {
        char temp = aligned_seq2[k];
        aligned_seq2[k] = aligned_seq2[pos2 - k - 1];
        aligned_seq2[pos2 - k - 1] = temp;
    }
}

void SequenceAligner_free(SequenceAligner *aligner) {
    free(aligner->seq1);
    free(aligner->seq2);
    for (int i = 0; i <= strlen(aligner->seq1); i++) {
        free(aligner->score_matrix[i]);
        free(aligner->traceback_matrix[i]);
    }
    free(aligner->score_matrix);
    free(aligner->traceback_matrix);
}

void main() {
    SequenceAligner aligner;
    SequenceAligner_init(&aligner, "AGCTG", "CGTAT");
    SequenceAligner_initialize_matrices(&aligner);
    SequenceAligner_fill_matrices(&aligner);

    char aligned_seq1[100];
    char aligned_seq2[100];
    SequenceAligner_backtrack(&aligner, aligned_seq1, aligned_seq2);

    printf("%s\n", aligned_seq1);
    printf("%s\n", aligned_seq2);

    SequenceAligner_free(&aligner);
}