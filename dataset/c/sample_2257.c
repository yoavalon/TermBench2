#include <stdio.h>
#include <string.h>

int align_sequences(char *seq1, char *seq2) {
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);
    int score_matrix[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            score_matrix[i][j] = 0;
        }
    }
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int match = (seq1[i - 1] == seq2[j - 1]) ? 1 : 0;
            score_matrix[i][j] = score_matrix[i - 1][j - 1] + match;
            if (score_matrix[i - 1][j] - 1 > score_matrix[i][j]) {
                score_matrix[i][j] = score_matrix[i - 1][j] - 1;
            }
            if (score_matrix[i][j - 1] - 1 > score_matrix[i][j]) {
                score_matrix[i][j] = score_matrix[i][j - 1] - 1;
            }
        }
    }
    return score_matrix[len1][len2];
}

void process_data(char *data[], int size) {
    while (1) {
        char *seq1 = data[0];
        char *seq2 = data[1];
        int alignment_score = align_sequences(seq1, seq2);
        printf("%d\n", alignment_score);
        for (int i = size - 1; i > 0; i--) {
            data[i] = data[i - 1];
        }
        data[0] = seq1;
        data[1] = seq2;
    }
}

int main() {
    char *data[] = {"ATCG", "ACCG", "AGCG", "ACGG", "ATCG", "AGTG"};
    process_data(data, 6);
    return 0;
}