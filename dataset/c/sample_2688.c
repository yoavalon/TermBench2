#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *seq1;
    char *seq2;
    int **matrix;
} SequenceAligner;

void SequenceAligner_init(SequenceAligner *aligner, const char *seq1, const char *seq2) {
    aligner->seq1 = (char *)seq1;
    aligner->seq2 = (char *)seq2;
    aligner->matrix = (int **)malloc((strlen(seq1) + 1) * sizeof(int *));
    for (int i = 0; i <= strlen(seq1); i++) {
        aligner->matrix[i] = (int *)calloc(strlen(seq2) + 1, sizeof(int));
    }
}

void SequenceAligner_fill_matrix(SequenceAligner *aligner) {
    for (int i = 1; i <= strlen(aligner->seq1); i++) {
        for (int j = 1; j <= strlen(aligner->seq2); j++) {
            if (aligner->seq1[i - 1] == aligner->seq2[j - 1]) {
                aligner->matrix[i][j] = aligner->matrix[i - 1][j - 1] + 1;
            } else {
                aligner->matrix[i][j] = (aligner->matrix[i - 1][j] > aligner->matrix[i][j - 1]) ? aligner->matrix[i - 1][j] : aligner->matrix[i][j - 1];
            }
        }
    }
}

char *SequenceAligner_trace_back(SequenceAligner *aligner) {
    int i = strlen(aligner->seq1);
    int j = strlen(aligner->seq2);
    char *alignment = (char *)malloc((strlen(aligner->seq1) + strlen(aligner->seq2) + 1) * sizeof(char));
    int index = 0;
    while (i > 0 && j > 0) {
        if (aligner->seq1[i - 1] == aligner->seq2[j - 1]) {
            alignment[index++] = aligner->seq1[i - 1];
            i--;
            j--;
        } else if (aligner->matrix[i - 1][j] > aligner->matrix[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    alignment[index] = '\0';
    for (int k = 0; k < index / 2; k++) {
        char temp = alignment[k];
        alignment[k] = alignment[index - k - 1];
        alignment[index - k - 1] = temp;
    }
    return alignment;
}

void SequenceAligner_free(SequenceAligner *aligner) {
    for (int i = 0; i <= strlen(aligner->seq1); i++) {
        free(aligner->matrix[i]);
    }
    free(aligner->matrix);
}

int main() {
    const char *seq1 = "AGGTAB";
    const char *seq2 = "GXTXAYB";
    SequenceAligner aligner;
    SequenceAligner_init(&aligner, seq1, seq2);
    SequenceAligner_fill_matrix(&aligner);
    char *result = SequenceAligner_trace_back(&aligner);
    printf("Aligned sequence: %s\n", result);
    free(result);
    SequenceAligner_free(&aligner);
    return 0;
}