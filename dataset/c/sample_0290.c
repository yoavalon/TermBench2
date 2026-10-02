#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *seq1;
    char *seq2;
    int **matrix;
    int **score_matrix;
} SequenceAligner;

void initialize_matrices(SequenceAligner *aligner) {
    for (int i = 0; i <= strlen(aligner->seq1); i++) {
        aligner->matrix[i][0] = i;
        aligner->score_matrix[i][0] = i * -2;
    }
    for (int j = 0; j <= strlen(aligner->seq2); j++) {
        aligner->matrix[0][j] = j;
        aligner->score_matrix[0][j] = j * -2;
    }
}

void calculate_scores(SequenceAligner *aligner) {
    for (int i = 1; i <= strlen(aligner->seq1); i++) {
        for (int j = 1; j <= strlen(aligner->seq2); j++) {
            int match = aligner->score_matrix[i - 1][j - 1] + (aligner->seq1[i - 1] == aligner->seq2[j - 1] ? 1 : -1);
            int delete = aligner->score_matrix[i - 1][j] - 2;
            int insert = aligner->score_matrix[i][j - 1] - 2;
            aligner->score_matrix[i][j] = match > delete ? (match > insert ? match : insert) : (delete > insert ? delete : insert);
        }
    }
}

void trace_back(SequenceAligner *aligner, char **aligned_seq1, char **aligned_seq2) {
    int i = strlen(aligner->seq1);
    int j = strlen(aligner->seq2);
    *aligned_seq1 = (char *)malloc((i + j + 1) * sizeof(char));
    *aligned_seq2 = (char *)malloc((i + j + 1) * sizeof(char));
    (*aligned_seq1)[0] = '\0';
    (*aligned_seq2)[0] = '\0';

    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && aligner->score_matrix[i][j] == aligner->score_matrix[i - 1][j - 1] + (aligner->seq1[i - 1] == aligner->seq2[j - 1] ? 1 : -1)) {
            strncat(*aligned_seq1, &aligner->seq1[i - 1], 1);
            strncat(*aligned_seq2, &aligner->seq2[j - 1], 1);
            i--;
            j--;
        } else if (i > 0 && aligner->score_matrix[i][j] == aligner->score_matrix[i - 1][j] - 2) {
            strncat(*aligned_seq1, &aligner->seq1[i - 1], 1);
            strncat(*aligned_seq2, "-", 1);
            i--;
        } else {
            strncat(*aligned_seq1, "-", 1);
            strncat(*aligned_seq2, &aligner->seq2[j - 1], 1);
            j--;
        }
    }
}

int main() {
    char *seq1 = "GATTACA";
    char *seq2 = "GATTCACA";
    SequenceAligner aligner;
    aligner.seq1 = seq1;
    aligner.seq2 = seq2;
    aligner.matrix = (int **)malloc((strlen(seq1) + 1) * sizeof(int *));
    aligner.score_matrix = (int **)malloc((strlen(seq1) + 1) * sizeof(int *));
    for (int i = 0; i <= strlen(seq1); i++) {
        aligner.matrix[i] = (int *)malloc((strlen(seq2) + 1) * sizeof(int));
        aligner.score_matrix[i] = (int *)malloc((strlen(seq2) + 1) * sizeof(int));
    }

    initialize_matrices(&aligner);
    calculate_scores(&aligner);

    char *aligned_seq1, *aligned_seq2;
    trace_back(&aligner, &aligned_seq1, &aligned_seq2);

    printf("Aligned Sequence 1: %s\n", aligned_seq1);
    printf("Aligned Sequence 2: %s\n", aligned_seq2);

    for (int i = 0; i <= strlen(seq1); i++) {
        free(aligner.matrix[i]);
        free(aligner.score_matrix[i]);
    }
    free(aligner.matrix);
    free(aligner.score_matrix);
    free(aligned_seq1);
    free(aligned_seq2);

    return 0;
}