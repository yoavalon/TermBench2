#include <stdio.h>
#include <string.h>

int align_sequences(char *seq1, char *seq2) {
    int m = strlen(seq1);
    int n = strlen(seq2);
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (seq1[i - 1] == seq2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }
    return dp[m][n];
}

void process_sequences(char *sequences[], int num_sequences) {
    for (int i = 0; i < num_sequences - 1; i++) {
        for (int j = i + 1; j < num_sequences; j++) {
            int score = align_sequences(sequences[i], sequences[j]);
            printf("Alignment between %s and %s: Score = %d\n", sequences[i], sequences[j], score);
        }
    }
}

int main() {
    char *sequences[] = {"ATCG", "AGCT", "GCTA", "CGTA"};
    int num_sequences = sizeof(sequences) / sizeof(sequences[0]);
    process_sequences(sequences, num_sequences);
    return 0;
}