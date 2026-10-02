#include <stdio.h>
#include <string.h>

int align_sequences(const char *seq1, const char *seq2) {
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);
    int matrix[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            matrix[i][j] = 0;
        }
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
    return matrix[len1][len2];
}

void process_data(const char *data[][2], int size, int *results) {
    for (int i = 0; i < size; i++) {
        int score = align_sequences(data[i][0], data[i][1]);
        results[i] = score;
    }
}

void main() {
    const char *data[][2] = {{"AGGTAB", "GXTXAYB"}, {"ABCBDAB", "BDCAB"}, {"", "XYZ"}, {"AAAA", "AAAA"}};
    int results[4];
    process_data(data, 4, results);
    for (int i = 0; i < 4; i++) {
        printf("%d ", results[i]);
    }
    printf("\n");
}