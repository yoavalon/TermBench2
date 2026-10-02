#include <stdio.h>
#include <string.h>

int genomic_align(const char *seq1, const char *seq2) {
    int m = strlen(seq1);
    int n = strlen(seq2);
    int score[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            score[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int match = score[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1]);
            int delete = score[i - 1][j] - 1;
            int insert = score[i][j - 1] - 1;
            score[i][j] = (match > delete) ? ((match > insert) ? match : insert) : ((delete > insert) ? delete : insert);
        }
    }
    return score[m][n];
}

int main() {
    const char *seq1 = "ATCG";
    const char *seq2 = "ACGT";
    int result = genomic_align(seq1, seq2);
    printf("%d\n", result);
    return 0;
}