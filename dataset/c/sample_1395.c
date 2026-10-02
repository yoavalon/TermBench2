#include <stdio.h>
#include <string.h>

int align_sequences(const char *seq1, const char *seq2) {
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);
    int dp[len1 + 1][len2 + 1];
    
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            dp[i][j] = 0;
        }
    }
    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (seq1[i - 1] == seq2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }
    
    return dp[len1][len2];
}

void process_data(const char *data[][2], int size, int *results) {
    for (int i = 0; i < size; i++) {
        const char *seq1 = data[i][0];
        const char *seq2 = data[i][1];
        int score = align_sequences(seq1, seq2);
        results[i] = score;
    }
}

void main() {
    const char *data[][2] = {{"AGCT", "AGGT"}, {"AACCGG", "AACCAT"}};
    int results[2];
    process_data(data, 2, results);
    printf("%d %d\n", results[0], results[1]);
}