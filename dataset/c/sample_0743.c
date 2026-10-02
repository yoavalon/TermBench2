#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int align(const char *seq1, const char *seq2, int i, int j, int **memo) {
    if (i == 0 || j == 0) {
        return (i > j) ? i : j;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    if (seq1[i - 1] == seq2[j - 1]) {
        memo[i][j] = align(seq1, seq2, i - 1, j - 1, memo);
    } else {
        memo[i][j] = 1 + (align(seq1, seq2, i - 1, j, memo) < align(seq1, seq2, i, j - 1, memo) ? 
                         (align(seq1, seq2, i - 1, j, memo) < align(seq1, seq2, i - 1, j - 1, memo) ? align(seq1, seq2, i - 1, j, memo) : align(seq1, seq2, i - 1, j - 1, memo)) : 
                         (align(seq1, seq2, i, j - 1, memo) < align(seq1, seq2, i - 1, j - 1, memo) ? align(seq1, seq2, i, j - 1, memo) : align(seq1, seq2, i - 1, j - 1, memo)));
    }
    return memo[i][j];
}

int main() {
    const char *seq1 = "AGGTAB";
    const char *seq2 = "GXTXAYB";
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);
    int **memo = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        memo[i] = (int *)malloc((len2 + 1) * sizeof(int));
        for (int j = 0; j <= len2; j++) {
            memo[i][j] = -1;
        }
    }
    printf("%d\n", align(seq1, seq2, len1, len2, memo));
    for (int i = 0; i <= len1; i++) {
        free(memo[i]);
    }
    free(memo);
    return 0;
}