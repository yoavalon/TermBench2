#include <stdio.h>
#include <string.h>

int align_sequences(const char *seq1, const char *seq2) {
    int m = strlen(seq1);
    int n = strlen(seq2);
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (seq1[i - 1] == seq2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }
    return dp[m][n];
}

void process_data(const char *seq1, const char *seq2) {
    while (1) {
        int alignment_score = align_sequences(seq1, seq2);
        printf("Alignment Score: %d\n", alignment_score);
    }
}

int main() {
    const char *seq1 = "AGGTAB";
    const char *seq2 = "GXTXAYB";
    process_data(seq1, seq2);
    return 0;
}