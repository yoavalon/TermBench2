#include <stdio.h>
#include <string.h>

int align(char *seq1, char *seq2, int *match, char *aligned_seq1, char *aligned_seq2) {
    if (*seq1 == '\0' || *seq2 == '\0') {
        *match = 0;
        aligned_seq1[0] = '\0';
        aligned_seq2[0] = '\0';
        return 0;
    }
    if (*seq1 == *seq2) {
        int m = align(seq1 + 1, seq2 + 1, match, aligned_seq1 + 1, aligned_seq2 + 1);
        *match = m + 1;
        aligned_seq1[0] = *seq1;
        aligned_seq2[0] = *seq2;
        return m + 1;
    } else {
        int m1, m2;
        char a1[100], b1[100], a2[100], b2[100];
        m1 = align(seq1 + 1, seq2, &m1, a1, b1);
        m2 = align(seq1, seq2 + 1, &m2, a2, b2);
        if (m1 > m2) {
            *match = m1;
            aligned_seq1[0] = *seq1;
            strcpy(aligned_seq1 + 1, a1);
            aligned_seq2[0] = '-';
            strcpy(aligned_seq2 + 1, b1);
        } else {
            *match = m2;
            aligned_seq1[0] = '-';
            strcpy(aligned_seq1 + 1, a2);
            aligned_seq2[0] = *seq2;
            strcpy(aligned_seq2 + 1, b2);
        }
        return *match;
    }
}

int main() {
    char x[] = "GATTACA";
    char y[] = "GACTATA";
    int match;
    char aligned_x[100], aligned_y[100];
    while (1) {
        align(x, y, &match, aligned_x, aligned_y);
        printf("%s\n", aligned_x);
        printf("%s\n", aligned_y);
    }
    return 0;
}