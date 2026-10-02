#include <stdio.h>
#include <string.h>

int align(const char *seq1, const char *seq2, int *score, char *alignment) {
    if (*seq1 == '\0' || *seq2 == '\0') {
        *score = 0;
        *alignment = '\0';
        return 0;
    }
    if (*seq1 == *seq2) {
        int temp_score;
        char temp_alignment[100];
        align(seq1 + 1, seq2 + 1, &temp_score, temp_alignment);
        *score = temp_score + 1;
        sprintf(alignment, "%c%s", *seq1, temp_alignment);
        return 0;
    } else {
        int score1, score2;
        char alignment1[100], alignment2[100];
        align(seq1 + 1, seq2, &score1, alignment1);
        align(seq1, seq2 + 1, &score2, alignment2);
        if (score1 > score2) {
            *score = score1;
            sprintf(alignment, "-%s", alignment1);
        } else {
            *score = score2;
            sprintf(alignment, "%s-", alignment2);
        }
        return 0;
    }
}

int main() {
    const char *seq1 = "AGCTG";
    const char *seq2 = "AGGCT";
    int score;
    char alignment[100];
    align(seq1, seq2, &score, alignment);
    printf("%d %s\n", score, alignment);
    return 0;
}