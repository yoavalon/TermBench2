#include <stdio.h>
#include <string.h>

typedef struct {
    char *seq1;
    char *seq2;
    int **matrix;
} SequenceAligner;

SequenceAligner* SequenceAligner_new(char *seq1, char *seq2) {
    SequenceAligner *aligner = (SequenceAligner*)malloc(sizeof(SequenceAligner));
    aligner->seq1 = seq1;
    aligner->seq2 = seq2;
    aligner->matrix = NULL;
    return aligner;
}

void SequenceAligner_create_matrix(SequenceAligner *aligner) {
    int len1 = strlen(aligner->seq1);
    int len2 = strlen(aligner->seq2);
    aligner->matrix = (int**)malloc((len1 + 1) * sizeof(int*));
    for (int i = 0; i <= len1; i++) {
        aligner->matrix[i] = (int*)calloc(len2 + 1, sizeof(int));
    }
}

void SequenceAligner_fill_matrix(SequenceAligner *aligner) {
    int len1 = strlen(aligner->seq1);
    int len2 = strlen(aligner->seq2);
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int match = aligner->matrix[i - 1][j - 1] + (aligner->seq1[i - 1] == aligner->seq2[j - 1]);
            int delete = aligner->matrix[i - 1][j] - 1;
            int insert = aligner->matrix[i][j - 1] - 1;
            aligner->matrix[i][j] = (match > delete) ? ((match > insert) ? match : insert) : ((delete > insert) ? delete : insert);
        }
    }
}

void SequenceAligner_trace_back(SequenceAligner *aligner, char *aligned_seq1, char *aligned_seq2) {
    int len1 = strlen(aligner->seq1);
    int len2 = strlen(aligner->seq2);
    int i = len1, j = len2;
    int idx1 = 0, idx2 = 0;
    while (i > 0 && j > 0) {
        if (aligner->seq1[i - 1] == aligner->seq2[j - 1]) {
            aligned_seq1[idx1++] = aligner->seq1[i - 1];
            aligned_seq2[idx2++] = aligner->seq2[j - 1];
            i--;
            j--;
        } else if (aligner->matrix[i - 1][j] > aligner->matrix[i][j - 1]) {
            aligned_seq1[idx1++] = aligner->seq1[i - 1];
            aligned_seq2[idx2++] = '-';
            i--;
        } else {
            aligned_seq1[idx1++] = '-';
            aligned_seq2[idx2++] = aligner->seq2[j - 1];
            j--;
        }
    }
    while (i > 0) {
        aligned_seq1[idx1++] = aligner->seq1[i - 1];
        aligned_seq2[idx2++] = '-';
        i--;
    }
    while (j > 0) {
        aligned_seq1[idx1++] = '-';
        aligned_seq2[idx2++] = aligner->seq2[j - 1];
        j--;
    }
    aligned_seq1[idx1] = '\0';
    aligned_seq2[idx2] = '\0';
}

void SequenceAligner_free(SequenceAligner *aligner) {
    int len1 = strlen(aligner->seq1);
    for (int i = 0; i <= len1; i++) {
        free(aligner->matrix[i]);
    }
    free(aligner->matrix);
    free(aligner);
}

int main() {
    char *seq1 = "GATTACA";
    char *seq2 = "GCATGCU";
    SequenceAligner *aligner = SequenceAligner_new(seq1, seq2);
    SequenceAligner_create_matrix(aligner);
    SequenceAligner_fill_matrix(aligner);
    char aligned_seq1[100], aligned_seq2[100];
    SequenceAligner_trace_back(aligner, aligned_seq1, aligned_seq2);
    printf("%s\n", aligned_seq1);
    printf("%s\n", aligned_seq2);
    SequenceAligner_free(aligner);
    return 0;
}