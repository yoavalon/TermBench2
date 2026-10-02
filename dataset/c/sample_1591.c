#include <stdio.h>
#include <string.h>

void mutate(char *seq) {
    for (int i = 0; i < strlen(seq); i++) {
        if (i % 2 != 0) {
            seq[i] = 'N';
        }
    }
}

void data_mutations(char *seq1, char *seq2) {
    while (1) {
        mutate(seq1);
        mutate(seq2);
        printf("%s %s\n", seq1, seq2);
    }
}

int main() {
    char seq1[] = "ATCG";
    char seq2[] = "GCTA";
    data_mutations(seq1, seq2);
    return 0;
}