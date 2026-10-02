#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *seq1;
    char *seq2;
    int **matrix;
} SequenceAligner;

void SequenceAligner_init(SequenceAligner *aligner, const char *seq1, const char *seq2) {
    aligner->seq1 = strdup(seq1);
    aligner->seq2 = strdup(seq2);
    aligner->matrix = (int **)malloc((strlen(seq1) + 1) * sizeof(int *));
    for (int i = 0; i <= strlen(seq1); i++) {
        aligner->matrix[i] = (int *)malloc((strlen(seq2) + 1) * sizeof(int));
        for (int j = 0; j <= strlen(seq2); j++) {
            aligner->matrix[i][j] = 0;
        }
    }
}

void SequenceAligner_build_matrix(SequenceAligner *aligner) {
    for (int i = 0; i <= strlen(aligner->seq1); i++) {
        for (int j = 0; j <= strlen(aligner->seq2); j++) {
            if (i == 0 || j == 0) {
                aligner->matrix[i][j] = 0;
            } else if (aligner->seq1[i - 1] == aligner->seq2[j - 1]) {
                aligner->matrix[i][j] = aligner->matrix[i - 1][j - 1] + 1;
            } else {
                aligner->matrix[i][j] = (aligner->matrix[i - 1][j] > aligner->matrix[i][j - 1]) ? aligner->matrix[i - 1][j] : aligner->matrix[i][j - 1];
            }
        }
    }
}

void SequenceAligner_trace_back(SequenceAligner *aligner, char **aligned_seq1, char **aligned_seq2) {
    int i = strlen(aligner->seq1);
    int j = strlen(aligner->seq2);
    *aligned_seq1 = (char *)malloc((i + j + 2) * sizeof(char));
    *aligned_seq2 = (char *)malloc((i + j + 2) * sizeof(char));
    (*aligned_seq1)[0] = '\0';
    (*aligned_seq2)[0] = '\0';

    while (i > 0 && j > 0) {
        if (aligner->seq1[i - 1] == aligner->seq2[j - 1]) {
            strncat(*aligned_seq1, &aligner->seq1[i - 1], 1);
            strncat(*aligned_seq2, &aligner->seq2[j - 1], 1);
            i -= 1;
            j -= 1;
        } else if (aligner->matrix[i - 1][j] > aligner->matrix[i][j - 1]) {
            strncat(*aligned_seq1, &aligner->seq1[i - 1], 1);
            strncat(*aligned_seq2, "-", 1);
            i -= 1;
        } else {
            strncat(*aligned_seq1, "-", 1);
            strncat(*aligned_seq2, &aligner->seq2[j - 1], 1);
            j -= 1;
        }
    }

    while (i > 0) {
        strncat(*aligned_seq1, &aligner->seq1[i - 1], 1);
        strncat(*aligned_seq2, "-", 1);
        i -= 1;
    }

    while (j > 0) {
        strncat(*aligned_seq1, "-", 1);
        strncat(*aligned_seq2, &aligner->seq2[j - 1], 1);
        j -= 1;
    }

    for (i = 0; i < strlen(*aligned_seq1) / 2; i++) {
        char temp = (*aligned_seq1)[i];
        (*aligned_seq1)[i] = (*aligned_seq1)[strlen(*aligned_seq1) - i - 1];
        (*aligned_seq1)[strlen(*aligned_seq1) - i - 1] = temp;
    }

    for (i = 0; i < strlen(*aligned_seq2) / 2; i++) {
        char temp = (*aligned_seq2)[i];
        (*aligned_seq2)[i] = (*aligned_seq2)[strlen(*aligned_seq2) - i - 1];
        (*aligned_seq2)[strlen(*aligned_seq2) - i - 1] = temp;
    }
}

void SequenceAligner_free(SequenceAligner *aligner) {
    free(aligner->seq1);
    free(aligner->seq2);
    for (int i = 0; i <= strlen(aligner->seq1); i++) {
        free(aligner->matrix[i]);
    }
    free(aligner->matrix);
}

void main() {
    SequenceAligner aligner;
    SequenceAligner_init(&aligner, "AGGTAB", "GXTXAYB");
    SequenceAligner_build_matrix(&aligner);
    char *aligned_seq1, *aligned_seq2;
    SequenceAligner_trace_back(&aligner, &aligned_seq1, &aligned_seq2);
    printf("Aligned Sequence 1: %s\n", aligned_seq1);
    printf("Aligned Sequence 2: %s\n", aligned_seq2);
    SequenceAligner_free(&aligner);
    free(aligned_seq1);
    free(aligned_seq2);
}