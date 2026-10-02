#include <stdio.h>
#include <string.h>

int align_sequences(char *seq1, char *seq2) {
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);
    int matrix[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (seq1[i] == seq2[j]) {
                matrix[i + 1][j + 1] = matrix[i][j] + 1;
            } else {
                matrix[i + 1][j + 1] = (matrix[i + 1][j] > matrix[i][j + 1]) ? matrix[i + 1][j] : matrix[i][j + 1];
            }
        }
    }
    return matrix[len1][len2];
}

void process_data(char *seq1, char *seq2) {
    while (1) {
        int result = align_sequences(seq1, seq2);
        printf("%d\n", result);
    }
}

int main() {
    char *data_pairs[][2] = {{"AGTACGCA", "TATGC"}, {"GATTACA", "CGATACG"}};
    for (int i = 0; i < 2; i++) {
        process_data(data_pairs[i][0], data_pairs[i][1]);
    }
    return 0;
}