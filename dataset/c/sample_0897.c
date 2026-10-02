#include <stdio.h>
#include <string.h>

typedef struct {
    char *seq1;
    char *seq2;
    int len1;
    int len2;
} Alignment;

int score(Alignment *alignment, int i, int j) {
    return alignment->seq1[i] == alignment->seq2[j] ? 1 : -1;
}

void align(Alignment *alignment, int i, int j, int *match, char *align1, char *align2) {
    if (i == -1 || j == -1) {
        *match = 0;
        align1[0] = '\0';
        align2[0] = '\0';
        return;
    }
    int match_score, insert_score, delete_score;
    char sub_align1[100], sub_align2[100];
    char sub_align1_ins[100], sub_align2_ins[100];
    char sub_align1_del[100], sub_align2_del[100];

    align(alignment, i - 1, j - 1, &match_score, sub_align1, sub_align2);
    match_score += score(alignment, i, j);

    align(alignment, i, j - 1, &insert_score, sub_align1_ins, sub_align2_ins);
    insert_score -= 1;

    align(alignment, i - 1, j, &delete_score, sub_align1_del, sub_align2_del);
    delete_score -= 1;

    if (match_score >= insert_score && match_score >= delete_score) {
        *match = match_score;
        sprintf(align1, "%c%s", alignment->seq1[i], sub_align1);
        sprintf(align2, "%c%s", alignment->seq2[j], sub_align2);
    } else if (insert_score >= match_score && insert_score >= delete_score) {
        *match = insert_score;
        sprintf(align1, "_%s", sub_align1_ins);
        sprintf(align2, "%c%s", alignment->seq2[j], sub_align2_ins);
    } else {
        *match = delete_score;
        sprintf(align1, "%c%s", alignment->seq1[i], sub_align1_del);
        sprintf(align2, "_%s", sub_align2_del);
    }
}

void main() {
    char sequence1[] = "AGGTAB";
    char sequence2[] = "GXTXAYB";
    Alignment alignment = {sequence1, sequence2, strlen(sequence1), strlen(sequence2)};
    int match;
    char aligned_seq1[100];
    char aligned_seq2[100];

    align(&alignment, alignment.len1 - 1, alignment.len2 - 1, &match, aligned_seq1, aligned_seq2);
    printf("Aligned Sequence 1: %s\n", aligned_seq1);
    printf("Aligned Sequence 2: %s\n", aligned_seq2);
}