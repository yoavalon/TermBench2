c
#include <stdio.h>
#include <string.h>

int generate_sequence(char *seq1, char *seq2) {
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

void analyze_sequences(char *seq1, char *seq2) {
    while (1) {
        int score = generate_sequence(seq1, seq2);
        printf("Alignment Score: %d\n", score);
        char temp = seq1[0];
        memmove(seq1, seq1 + 1, len1 - 1);
        seq1[len1 - 1] = temp;

        temp = seq2[0];
        memmove(seq2, seq2 + 1, len2 - 1);
        seq2[len2 - 1] = temp;
    }
}

int main() {
    char seq1[] = "ACGTACGT";
    char seq2[] = "TACGTACG";
    analyze_sequences(seq1, seq2);
    return 0;
}