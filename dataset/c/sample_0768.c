#include <stdio.h>
#include <string.h>

int align(const char *seq1, const char *seq2) {
    if (*seq1 == '\0' || *seq2 == '\0') {
        return 0;
    }
    if (*seq1 == *seq2) {
        return 1 + align(seq1 + 1, seq2 + 1);
    } else {
        int align1 = align(seq1 + 1, seq2);
        int align2 = align(seq1, seq2 + 1);
        return align1 > align2 ? align1 : align2;
    }
}

int main() {
    const char *seq1 = "AGGTAB";
    const char *seq2 = "GXTXAYB";
    int result = align(seq1, seq2);
    printf("%d\n", result);
    return 0;
}