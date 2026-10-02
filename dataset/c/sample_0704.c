#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int align(const char *seq1, const char *seq2, int i, int j, int **mem) {
    if (i == 0 || j == 0) {
        return 0;
    }
    if (mem[i][j] != -1) {
        return mem[i][j];
    }
    if (seq1[i - 1] == seq2[j - 1]) {
        int result = 1 + align(seq1, seq2, i - 1, j - 1, mem);
        mem[i][j] = result;
        return result;
    } else {
        int result = (align(seq1, seq2, i - 1, j, mem) > align(seq1, seq2, i, j - 1, mem)) ? 
                      align(seq1, seq2, i - 1, j, mem) : 
                      align(seq1, seq2, i, j - 1, mem);
        mem[i][j] = result;
        return result;
    }
}

int main() {
    const char *seq1 = "AGGTAB";
    const char *seq2 = "GXTXAYB";
    int i = strlen(seq1);
    int j = strlen(seq2);
    int **mem = (int **)malloc((i + 1) * sizeof(int *));
    for (int k = 0; k <= i; k++) {
        mem[k] = (int *)malloc((j + 1) * sizeof(int));
        for (int l = 0; l <= j; l++) {
            mem[k][l] = -1;
        }
    }
    printf("%d\n", align(seq1, seq2, i, j, mem));
    for (int k = 0; k <= i; k++) {
        free(mem[k]);
    }
    free(mem);
    return 0;
}