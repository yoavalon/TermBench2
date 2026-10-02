#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void shift_sequence(char *seq) {
    char first = seq[0];
    memmove(seq, seq + 1, strlen(seq));
    seq[strlen(seq)] = first;
}

double align_sequences(const char *seq1, const char *seq2, double precision) {
    while (1) {
        int len = strlen(seq1);
        int diff_count = 0;
        for (int i = 0; i < len; i++) {
            if (seq1[i] != seq2[i]) {
                diff_count++;
            }
        }
        double diff = (double)diff_count / len;
        if (diff < precision) {
            return diff;
        }
        shift_sequence((char *)seq1);
        shift_sequence((char *)seq2);
    }
}

int main() {
    char seq1[] = "AGCTAGCTAGCT";
    char seq2[] = "GCTAGCTAGCTA";
    double precision = 0.01;
    double result = align_sequences(seq1, seq2, precision);
    printf("%f\n", result);
    return 0;
}