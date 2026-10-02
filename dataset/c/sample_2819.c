#include <stdio.h>
#include <string.h>

int align(char *seq1, char *seq2) {
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
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }
    return dp[m][n];
}

void process() {
    char seq1[] = "ACGTGACGTG";
    char seq2[] = "GTCGTGTCGT";
    while (1) {
        int result = align(seq1, seq2);
        strcpy(seq1, seq2);
        char new_seq2[m + n + 1];
        strncpy(new_seq2, seq2, result);
        strcat(new_seq2, seq1 + result);
        strcpy(seq2, new_seq2);
        printf("%d\n", result);
    }
}

int main() {
    process();
    return 0;
}