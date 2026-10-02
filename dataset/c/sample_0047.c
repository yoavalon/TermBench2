#include <stdio.h>
#include <string.h>

void boundary_conditions(char *seq1, char *seq2, int max_length, int *i, int *j) {
    *i = 0;
    *j = 0;
    while (*i < strlen(seq1) && *j < strlen(seq2) && (*i + *j < max_length)) {
        if (seq1[*i] == seq2[*j]) {
            (*i)++;
            (*j)++;
        } else {
            (*i)++;
        }
    }
}

int main() {
    char seq1[] = "AGTAC";
    char seq2[] = "AGCTA";
    int max_length = 10;
    int i, j;
    boundary_conditions(seq1, seq2, max_length, &i, &j);
    printf("(%d, %d)\n", i, j);
    return 0;
}