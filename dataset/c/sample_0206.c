#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *seq1;
    char *seq2;
    int **matrix;
} SequenceAligner;

void SequenceAligner_init(SequenceAligner *aligner, char *seq1, char *seq2) {
    aligner->seq1 = seq1;
    aligner->seq2 = seq2;
    aligner->matrix = (int **)malloc((strlen(seq1) + 1) * sizeof(int *));
    for (int i = 0; i <= strlen(seq1); i++) {
        aligner->matrix[i] = (int *)malloc((strlen(seq2) + 1) * sizeof(int));
        memset(aligner->matrix[i], 0, (strlen(seq2) + 1) * sizeof(int));
    }
}

void initialize_matrix(SequenceAligner *aligner) {
    for (int i = 0; i <= strlen(aligner->seq1); i++) {
        aligner->matrix[i][0] = i;
    }
    for (int j = 0; j <= strlen(aligner->seq2); j++) {
        aligner->matrix[0][j] = j;
    }
}

void compute_similarity(SequenceAligner *aligner) {
    for (int i = 1; i <= strlen(aligner->seq1); i++) {
        for (int j = 1; j <= strlen(aligner->seq2); j++) {
            int match = aligner->matrix[i - 1][j - 1] + (aligner->seq1[i - 1] == aligner->seq2[j - 1]);
            int delete = aligner->matrix[i - 1][j] + 1;
            int insert = aligner->matrix[i][j - 1] + 1;
            aligner->matrix[i][j] = match < delete ? (match < insert ? match : insert) : (delete < insert ? delete : insert);
        }
    }
}

void trace_back(SequenceAligner *aligner, char *aligned_seq1, char *aligned_seq2) {
    int i = strlen(aligner->seq1);
    int j = strlen(aligner->seq2);
    int index1 = 0, index2 = 0;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && aligner->matrix[i][j] == aligner->matrix[i - 1][j - 1] + (aligner->seq1[i - 1] == aligner->seq2[j - 1])) {
            aligned_seq1[index1++] = aligner->seq1[i - 1];
            aligned_seq2[index2++] = aligner->seq2[j - 1];
            i--;
            j--;
        } else if (i > 0 && aligner->matrix[i][j] == aligner->matrix[i - 1][j] + 1) {
            aligned_seq1[index1++] = aligner->seq1[i - 1];
            aligned_seq2[index2++] = '-';
            i--;
        } else {
            aligned_seq1[index1++] = '-';
            aligned_seq2[index2++] = aligner->seq2[j - 1];
            j--;
        }
    }
    aligned_seq1[index1] = '\0';
    aligned_seq2[index2] = '\0';
    for (int k = 0; k < index1 / 2; k++) {
        char temp = aligned_seq1[k];
        aligned_seq1[k] = aligned_seq1[index1 - k - 1];
        aligned_seq1[index1 - k - 1] = temp;
    }
    for (int k = 0; k < index2 / 2; k++) {
        char temp = aligned_seq2[k];
        aligned_seq2[k] = aligned_seq2[index2 - k - 1];
        aligned_seq2[index2 - k - 1] = temp;
    }
}

void main() {
    char seq1[] = "AGGTAB";
    char seq2[] = "GXTXAYB";
    SequenceAligner aligner;
    SequenceAligner_init(&aligner, seq1, seq2);
    initialize_matrix(&aligner);
    compute_similarity(&aligner);
    char aligned_seq1[100], aligned_seq2[100];
    trace_back(&aligner, aligned_seq1, aligned_seq2);
    printf("Aligned Sequence 1: %s\n", aligned_seq1);
    printf("Aligned Sequence 2: %s\n", aligned_seq2);
    for (int i = 0; i <= strlen(seq1); i++) {
        free(aligner.matrix[i]);
    }
    free(aligner.matrix);
}