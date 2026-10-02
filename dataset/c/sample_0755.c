#include <stdio.h>
#include <string.h>

int align(const char *seq1, const char *seq2, int i, int j, int **memo, int len1, int len2) {
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    if (i == len1 || j == len2) {
        return 0;
    }
    int match = align(seq1, seq2, i + 1, j + 1, memo, len1, len2) + (seq1[i] == seq2[j]);
    int delete = align(seq1, seq2, i + 1, j, memo, len1, len2);
    int insert = align(seq1, seq2, i, j + 1, memo, len1, len2);
    int result = match > delete ? (match > insert ? match : insert) : (delete > insert ? delete : insert);
    memo[i][j] = result;
    return result;
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
    printf("%d\n", align(seq1, seq2, 0, 0, memo, len1, len2));
    for (int i = 0; i <= len1; i++) {
        free(memo[i]);
    }
    free(memo);
    return 0;
}