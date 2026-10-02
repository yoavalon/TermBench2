#include <stdio.h>
#include <string.h>

void process_sequences(const char *seq1, const char *seq2) {
    while (1) {
        char aligned[100] = "";
        int len1 = strlen(seq1);
        int len2 = strlen(seq2);
        int min_len = len1 < len2 ? len1 : len2;
        for (int i = 0; i < min_len; i++) {
            if (seq1[i] == seq2[i]) {
                strncat(aligned, "|", 1);
            } else {
                strncat(aligned, " ", 1);
            }
        }
        printf("%s\n", aligned);
    }
}

int main() {
    const char *seq1 = "ATCGATCGATCG";
    const char *seq2 = "ATAGATAGATAG";
    process_sequences(seq1, seq2);
    return 0;
}