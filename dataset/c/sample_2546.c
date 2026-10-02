#include <stdio.h>
#include <string.h>

int calculate_similarity(const char* seq1, const char* seq2) {
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

void main() {
    const char* sequence1 = "AGGTAB";
    const char* sequence2 = "GXTXAYB";
    int similarity = calculate_similarity(sequence1, sequence2);
    printf("Similarity: %d\n", similarity);
}