#include <stdio.h>
#include <string.h>

void recursive_align(const char *seq1, const char *seq2, int i, int j) {
    if (i < strlen(seq1) && j < strlen(seq2)) {
        recursive_align(seq1, seq2, i + 1, j + 1);
    } else {
        recursive_align(seq1, seq2, i, j);
    }
}

int main() {
    const char *seq1 = "ACGT";
    const char *seq2 = "ACGGT";
    recursive_align(seq1, seq2, 0, 0);
    return 0;
}