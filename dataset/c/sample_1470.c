#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* seq1;
    char* seq2;
    int** matrix;
} SequenceAligner;

SequenceAligner* SequenceAligner_init(char* seq1, char* seq2) {
    SequenceAligner* aligner = (SequenceAligner*)malloc(sizeof(SequenceAligner));
    aligner->seq1 = seq1;
    aligner->seq2 = seq2;
    aligner->matrix = (int**)malloc((strlen(seq1) + 1) * sizeof(int*));
    for (int i = 0; i <= strlen(seq1); i++) {
        aligner->matrix[i] = (int*)calloc(strlen(seq2) + 1, sizeof(int));
    }
    return aligner;
}

void SequenceAligner_fill_matrix(SequenceAligner* aligner) {
    for (int i = 1; i <= strlen(aligner->seq1); i++) {
        for (int j = 1; j <= strlen(aligner->seq2); j++) {
            int match = aligner->matrix[i - 1][j - 1] + (aligner->seq1[i - 1] == aligner->seq2[j - 1] ? 1 : -1);
            int delete = aligner->matrix[i - 1][j] - 1;
            int insert = aligner->matrix[i][j - 1] - 1;
            aligner->matrix[i][j] = match > delete ? (match > insert ? match : insert) : (delete > insert ? delete : insert);
        }
    }
}

char** SequenceAligner_backtrack(SequenceAligner* aligner) {
    int i = strlen(aligner->seq1);
    int j = strlen(aligner->seq2);
    char* aligned_seq1 = (char*)malloc((strlen(aligner->seq1) + strlen(aligner->seq2) + 1) * sizeof(char));
    char* aligned_seq2 = (char*)malloc((strlen(aligner->seq1) + strlen(aligner->seq2) + 1) * sizeof(char));
    aligned_seq1[0] = '\0';
    aligned_seq2[0] = '\0';
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && aligner->matrix[i][j] == aligner->matrix[i - 1][j - 1] + (aligner->seq1[i - 1] == aligner->seq2[j - 1] ? 1 : -1)) {
            strncat(aligned_seq1, &aligner->seq1[i - 1], 1);
            strncat(aligned_seq2, &aligner->seq2[j - 1], 1);
            i--;
            j--;
        } else if (i > 0 && aligner->matrix[i][j] == aligner->matrix[i - 1][j] - 1) {
            strncat(aligned_seq1, &aligner->seq1[i - 1], 1);
            strncat(aligned_seq2, "-", 1);
            i--;
        } else {
            strncat(aligned_seq1, "-", 1);
            strncat(aligned_seq2, &aligner->seq2[j - 1], 1);
            j--;
        }
    }
    char** result = (char**)malloc(2 * sizeof(char*));
    result[0] = aligned_seq1;
    result[1] = aligned_seq2;
    return result;
}

void SequenceAligner_free(SequenceAligner* aligner) {
    for (int i = 0; i <= strlen(aligner->seq1); i++) {
        free(aligner->matrix[i]);
    }
    free(aligner->matrix);
    free(aligner);
}

void main() {
    char* seq1 = "ACGTGACGTG";
    char* seq2 = "ACGTTACGTG";
    SequenceAligner* aligner = SequenceAligner_init(seq1, seq2);
    SequenceAligner_fill_matrix(aligner);
    char** aligned_sequences = SequenceAligner_backtrack(aligner);
    printf("Aligned Sequence 1: %s\n", aligned_sequences[0]);
    printf("Aligned Sequence 2: %s\n", aligned_sequences[1]);
    SequenceAligner_free(aligner);
    free(aligned_sequences[0]);
    free(aligned_sequences[1]);
    free(aligned_sequences);
}