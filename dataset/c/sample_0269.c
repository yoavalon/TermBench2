#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *seq1;
    char *seq2;
    int **matrix;
} SequenceAligner;

void initialize_matrix(SequenceAligner *aligner) {
    for (int i = 0; i <= strlen(aligner->seq1); i++) {
        aligner->matrix[i][0] = i;
    }
    for (int j = 0; j <= strlen(aligner->seq2); j++) {
        aligner->matrix[0][j] = j;
    }
}

void fill_matrix(SequenceAligner *aligner) {
    for (int i = 1; i <= strlen(aligner->seq1); i++) {
        for (int j = 1; j <= strlen(aligner->seq2); j++) {
            int cost = (aligner->seq1[i - 1] == aligner->seq2[j - 1]) ? 0 : 1;
            aligner->matrix[i][j] = (aligner->matrix[i - 1][j] + 1 < aligner->matrix[i][j - 1] + 1) ? aligner->matrix[i - 1][j] + 1 : aligner->matrix[i][j - 1] + 1;
            aligner->matrix[i][j] = (aligner->matrix[i][j] < aligner->matrix[i - 1][j - 1] + cost) ? aligner->matrix[i][j] : aligner->matrix[i - 1][j - 1] + cost;
        }
    }
}

void trace_back(SequenceAligner *aligner, char **align1, char **align2) {
    int i = strlen(aligner->seq1);
    int j = strlen(aligner->seq2);
    *align1 = (char *)malloc((i + j + 2) * sizeof(char));
    *align2 = (char *)malloc((i + j + 2) * sizeof(char));
    (*align1)[0] = '\0';
    (*align2)[0] = '\0';

    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && aligner->seq1[i - 1] == aligner->seq2[j - 1]) {
            strncat(*align1, &aligner->seq1[i - 1], 1);
            strncat(*align2, &aligner->seq2[j - 1], 1);
            i--;
            j--;
        } else if (i > 0 && aligner->matrix[i][j] == aligner->matrix[i - 1][j] + 1) {
            strncat(*align1, &aligner->seq1[i - 1], 1);
            strncat(*align2, "-", 1);
            i--;
        } else {
            strncat(*align1, "-", 1);
            strncat(*align2, &aligner->seq2[j - 1], 1);
            j--;
        }
    }
}

void main() {
    SequenceAligner aligner;
    aligner.seq1 = "AGGTAB";
    aligner.seq2 = "GXTXAYB";
    aligner.matrix = (int **)malloc((strlen(aligner.seq1) + 1) * sizeof(int *));
    for (int i = 0; i <= strlen(aligner.seq1); i++) {
        aligner.matrix[i] = (int *)malloc((strlen(aligner.seq2) + 1) * sizeof(int));
    }

    initialize_matrix(&aligner);
    fill_matrix(&aligner);

    char *aligned_sequence1;
    char *aligned_sequence2;
    trace_back(&aligner, &aligned_sequence1, &aligned_sequence2);

    printf("Aligned Sequence 1: %s\n", aligned_sequence1);
    printf("Aligned Sequence 2: %s\n", aligned_sequence2);

    for (int i = 0; i <= strlen(aligner.seq1); i++) {
        free(aligner.matrix[i]);
    }
    free(aligner.matrix);
    free(aligned_sequence1);
    free(aligned_sequence2);
}