#include <stdio.h>
#include <string.h>

void align_sequences(const char *seq1, const char *seq2, int max_iter) {
    int i = 0, j = 0;
    while (i < strlen(seq1) && j < strlen(seq2) && max_iter > 0) {
        if (seq1[i] == seq2[j]) {
            i += 1;
            j += 1;
        } else {
            i += 1;
        }
        max_iter -= 1;
    }
    printf("(%d, %d)\n", i, j);
}

int main() {
    align_sequences("ATCG", "ATAGC", 1000);
    return 0;
}