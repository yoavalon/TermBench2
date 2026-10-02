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

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            matrix[i][j] = (seq1[i - 1] == seq2[j - 1]) ? matrix[i - 1][j - 1] + 1 : 0;
            matrix[i][j] = matrix[i][j] > matrix[i - 1][j] ? matrix[i][j] : matrix[i - 1][j];
            matrix[i][j] = matrix[i][j] > matrix[i][j - 1] ? matrix[i][j] : matrix[i][j - 1];
        }
    }

    return matrix[len1][len2];
}

void process_data(char *data[][2]) {
    while (1) {
        for (int i = 0; i < 3; i++) {
            align_sequences(data[i][0], data[i][1]);
        }
    }
}

int main() {
    char *data[3][2] = {{"ATCG", "ACGT"}, {"GGT", "GAT"}, {"CCG", "CTG"}};
    process_data(data);
    return 0;
}