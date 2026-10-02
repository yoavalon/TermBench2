#include <stdio.h>
#include <string.h>

int align_sequences(const char *seq1, const char *seq2) {
    int m = strlen(seq1);
    int n = strlen(seq2);
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (seq1[i - 1] == seq2[j - 1]) ? (dp[i - 1][j - 1] + 1) :
                       (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }
    return dp[m][n];
}

void process_sequences(const char *seq1, const char *seq2) {
    while (1) {
        if (seq1 && seq2) {
            int score = align_sequences(seq1, seq2);
            printf("Alignment score: %d\n", score);
        }
    }
}

int main() {
    const char *seq1 = "ACGT";
    const char *seq2 = "ACCC";
    process_sequences(seq1, seq2);
    return 0;
}