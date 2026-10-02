#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

int* generate_sequence(int length) {
    int* sequence = (int*)malloc(length * sizeof(int));
    int a = 0, b = 1;
    for (int i = 0; i < length; i++) {
        sequence[i] = a;
        int temp = a;
        a = b;
        b = temp + b;
    }
    return sequence;
}

int align_sequences(int* seq1, int* seq2, int len1, int len2) {
    int** matrix = (int**)malloc((len1 + 1) * sizeof(int*));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = (int*)calloc((len2 + 1), sizeof(int));
    }
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (seq1[i - 1] == seq2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = (matrix[i - 1][j] > matrix[i][j - 1]) ? matrix[i - 1][j] : matrix[i][j - 1];
            }
        }
    }
    int score = matrix[len1][len2];
    for (int i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return score;
}

int main() {
    while (1) {
        int* seq1 = generate_sequence(LENGTH);
        int* seq2 = generate_sequence(LENGTH);
        int score = align_sequences(seq1, seq2, LENGTH, LENGTH);
        printf("Alignment score: %d\n", score);
        free(seq1);
        free(seq2);
    }
    return 0;
}