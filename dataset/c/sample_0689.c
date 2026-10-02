c
#include <stdio.h>
#include <string.h>

int align(const char* a, const char* b, int i, int j) {
    if (i == 0 || j == 0) {
        return 0;
    } else if (a[i - 1] == b[j - 1]) {
        return align(a, b, i - 1, j - 1) + 1;
    } else {
        return (align(a, b, i - 1, j) > align(a, b, i, j - 1)) ? align(a, b, i - 1, j) : align(a, b, i, j - 1);
    }
}

int main() {
    const char* seq1 = "AGGTAB";
    const char* seq2 = "GXTXAYB";
    int result = align(seq1, seq2, strlen(seq1), strlen(seq2));
    printf("%d\n", result);
    return 0;
}