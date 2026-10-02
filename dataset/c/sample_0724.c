#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int align(const char *seq1, const char *seq2, int i, int j, int *memo) {
    if (i == 0 || j == 0) {
        return 0;
    }
    if (memo[i * strlen(seq2) + j] != -1) {
        return memo[i * strlen(seq2) + j];
    }
    if (seq1[i - 1] == seq2[j - 1]) {
        int result = 1 + align(seq1, seq2, i - 1, j - 1, memo);
        memo[i * strlen(seq2) + j] = result;
        return result;
    } else {
        int result = (align(seq1, seq2, i - 1, j, memo) > align(seq1, seq2, i, j - 1, memo)) 
                      ? align(seq1, seq2, i - 1, j, memo) 
                      : align(seq1, seq2, i, j - 1, memo);
        memo[i * strlen(seq2) + j] = result;
        return result;
    }
}

int longest_common_subsequence(const char *seq1, const char *seq2) {
    int *memo = (int *)malloc((strlen(seq1) + 1) * (strlen(seq2) + 1) * sizeof(int));
    for (int i = 0; i <= strlen(seq1); i++) {
        for (int j = 0; j <= strlen(seq2); j++) {
            memo[i * (strlen(seq2) + 1) + j] = -1;
        }
    }
    int result = align(seq1, seq2, strlen(seq1), strlen(seq2), memo);
    free(memo);
    return result;
}

int main() {
    const char *seq1 = "AGGTAB";
    const char *seq2 = "GXTXAYB";
    printf("%d\n", longest_common_subsequence(seq1, seq2));
    return 0;
}