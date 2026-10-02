#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* seq1;
    char* seq2;
    int** matrix;
} GenomicAligner;

GenomicAligner* GenomicAligner_init(char* seq1, char* seq2) {
    GenomicAligner* aligner = (GenomicAligner*)malloc(sizeof(GenomicAligner));
    aligner->seq1 = seq1;
    aligner->seq2 = seq2;
    aligner->matrix = (int**)malloc((strlen(seq1) + 1) * sizeof(int*));
    for (int i = 0; i <= strlen(seq1); i++) {
        aligner->matrix[i] = (int*)calloc(strlen(seq2) + 1, sizeof(int));
    }
    return aligner;
}

int _score(char a, char b) {
    return (a == b) ? 1 : -1;
}

void _fill_matrix(GenomicAligner* aligner) {
    for (int i = 1; i <= strlen(aligner->seq1); i++) {
        for (int j = 1; j <= strlen(aligner->seq2); j++) {
            int match = aligner->matrix[i - 1][j - 1] + _score(aligner->seq1[i - 1], aligner->seq2[j - 1]);
            int delete = aligner->matrix[i - 1][j] - 1;
            int insert = aligner->matrix[i][j - 1] - 1;
            aligner->matrix[i][j] = (match > delete) ? ((match > insert) ? match : insert) : ((delete > insert) ? delete : insert);
        }
    }
}

void _traceback(GenomicAligner* aligner, int i, int j, char* s1, char* s2) {
    if (i == 0 || j == 0) {
        return;
    }
    if (aligner->matrix[i][j] == aligner->matrix[i - 1][j - 1] + _score(aligner->seq1[i - 1], aligner->seq2[j - 1])) {
        _traceback(aligner, i - 1, j - 1, s1 - 1, s2 - 1);
        *(s1 - 1) = aligner->seq1[i - 1];
        *(s2 - 1) = aligner->seq2[j - 1];
    } else if (aligner->matrix[i][j] == aligner->matrix[i - 1][j] - 1) {
        _traceback(aligner, i - 1, j, s1 - 1, s2 - 1);
        *(s1 - 1) = aligner->seq1[i - 1];
        *(s2 - 1) = '-';
    } else {
        _traceback(aligner, i, j - 1, s1 - 1, s2 - 1);
        *(s1 - 1) = '-';
        *(s2 - 1) = aligner->seq2[j - 1];
    }
}

void align(GenomicAligner* aligner, char* aligned_seq1, char* aligned_seq2) {
    _fill_matrix(aligner);
    _traceback(aligner, strlen(aligner->seq1), strlen(aligner->seq2), aligned_seq1 + strlen(aligner->seq1), aligned_seq2 + strlen(aligner->seq2));
}

void GenomicAligner_free(GenomicAligner* aligner) {
    for (int i = 0; i <= strlen(aligner->seq1); i++) {
        free(aligner->matrix[i]);
    }
    free(aligner->matrix);
    free(aligner);
}

void main() {
    char seq1[] = "ACGTGACGTG";
    char seq2[] = "GTCGTGTCG";
    GenomicAligner* aligner = GenomicAligner_init(seq1, seq2);
    char aligned_seq1[20] = {0};
    char aligned_seq2[20] = {0};
    align(aligner, aligned_seq1, aligned_seq2);
    printf("Aligned Sequence 1: %s\n", aligned_seq1);
    printf("Aligned Sequence 2: %s\n", aligned_seq2);
    GenomicAligner_free(aligner);
}