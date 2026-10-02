#include <stdio.h>
#include <string.h>

int align_sequences(const char *seq1, const char *seq2) {
    int m = strlen(seq1);
    int n = strlen(seq2);
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = (seq1[i - 1] == seq2[j - 1]) ? 0 : 1;
            dp[i][j] = (dp[i - 1][j] + 1 < dp[i][j - 1] + 1) ? dp[i - 1][j] + 1 : dp[i][j - 1] + 1;
            dp[i][j] = (dp[i][j] < dp[i - 1][j - 1] + cost) ? dp[i][j] : dp[i - 1][j - 1] + cost;
        }
    }
    return dp[m][n];
}

int process_sequences(const char *seq1, const char *seq2) {
    return align_sequences(seq1, seq2);
}

int main() {
    const char *seq1 = "AGCT";
    const char *seq2 = "ACGT";
    const char *seq3 = "GATTACA";
    const char *seq4 = "GCTACGA";
    int result = process_sequences(seq1, seq2) + process_sequences(seq3, seq4);
    printf("%d\n", result);
    return 0;
}