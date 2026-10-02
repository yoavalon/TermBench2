#include <stdio.h>
#include <string.h>

int align_sequences(const char *seq1, const char *seq2) {
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);
    int dp[len1 + 1][len2 + 1];
    
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (seq1[i - 1] == seq2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }
    return dp[len1][len2];
}

void process_data(const char *data[][2], int size, int results[]) {
    for (int i = 0; i < size; i++) {
        int score = align_sequences(data[i][0], data[i][1]);
        results[i] = score;
    }
}

int main() {
    const char *data[][2] = {{"AGGTAB", "GXTXAYB"}, {"ABCDGH", "AEDFHR"}, {"XYZ", "XYZ"}};
    int results[3];
    process_data(data, 3, results);
    for (int i = 0; i < 3; i++) {
        printf("%d ", results[i]);
    }
    printf("\n");
    return 0;
}