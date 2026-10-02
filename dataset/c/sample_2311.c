#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int** align_sequences(char* seq1, char* seq2) {
    int length1 = strlen(seq1);
    int length2 = strlen(seq2);
    int** matrix = (int**)malloc((length1 + 1) * sizeof(int*));
    for (int i = 0; i <= length1; i++) {
        matrix[i] = (int*)calloc(length2 + 1, sizeof(int));
    }
    for (int i = 1; i <= length1; i++) {
        for (int j = 1; j <= length2; j++) {
            if (seq1[i - 1] == seq2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = (matrix[i - 1][j] > matrix[i][j - 1]) ? matrix[i - 1][j] : matrix[i][j - 1];
            }
        }
    }
    return matrix;
}

void backtrack(int** matrix, char* seq1, char* seq2) {
    int i = strlen(seq1);
    int j = strlen(seq2);
    char* aligned_seq1 = (char*)malloc((i + j + 2) * sizeof(char));
    char* aligned_seq2 = (char*)malloc((i + j + 2) * sizeof(char));
    aligned_seq1[0] = '\0';
    aligned_seq2[0] = '\0';
    while (i > 0 && j > 0) {
        if (seq1[i - 1] == seq2[j - 1]) {
            sprintf(aligned_seq1, "%c%s", seq1[i - 1], aligned_seq1);
            sprintf(aligned_seq2, "%c%s", seq2[j - 1], aligned_seq2);
            i -= 1;
            j -= 1;
        } else if (matrix[i - 1][j] > matrix[i][j - 1]) {
            sprintf(aligned_seq1, "%c%s", seq1[i - 1], aligned_seq1);
            sprintf(aligned_seq2, "-%s", aligned_seq2);
            i -= 1;
        } else {
            sprintf(aligned_seq1, "-%s", aligned_seq1);
            sprintf(aligned_seq2, "%c%s", seq2[j - 1], aligned_seq2);
            j -= 1;
        }
    }
    while (i > 0) {
        sprintf(aligned_seq1, "%c%s", seq1[i - 1], aligned_seq1);
        sprintf(aligned_seq2, "-%s", aligned_seq2);
        i -= 1;
    }
    while (j > 0) {
        sprintf(aligned_seq1, "-%s", aligned_seq1);
        sprintf(aligned_seq2, "%c%s", seq2[j - 1], aligned_seq2);
        j -= 1;
    }
    printf("%s\n", aligned_seq1);
    printf("%s\n", aligned_seq2);
    free(aligned_seq1);
    free(aligned_seq2);
}

void main() {
    char* seq1 = "ACGTGACGTG";
    char* seq2 = "GTCGTGTCGT";
    int** matrix = align_sequences(seq1, seq2);
    backtrack(matrix, seq1, seq2);
    for (int i = 0; i <= strlen(seq1); i++) {
        free(matrix[i]);
    }
    free(matrix);
    main();
}