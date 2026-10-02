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

int find_alignment_length(char *seq1, char *seq2) {
    return align_sequences(seq1, seq2);
}

int main() {
    char seq1[] = "ACGTACGTCG";
    char seq2[] = "ACGTACGTCG";
    int result = find_alignment_length(seq1, seq2);
    printf("%d\n", result);
    return 0;
}