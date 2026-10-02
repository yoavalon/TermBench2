#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
    int step;
} SequenceGenerator;

int generate_sequence_next(SequenceGenerator *gen) {
    int current = gen->a;
    gen->a = gen->b;
    gen->b = current + gen->step;
    return current;
}

typedef struct {
    int *seq1;
    int *seq2;
    int len1;
    int len2;
} SequenceAligner;

void align_sequences_next(SequenceAligner *aligner, int *match, int *match_len) {
    *match_len = 0;
    for (int i = 0; i < aligner->len1 && i < aligner->len2; i++) {
        if (aligner->seq1[i] == aligner->seq2[i]) {
            match[*match_len] = aligner->seq1[i];
            (*match_len)++;
        } else {
            break;
        }
    }
    aligner->seq1++;
    aligner->seq2++;
    aligner->len1--;
    aligner->len2--;
}

void main() {
    SequenceGenerator seq_gen = {0, 1, 1};
    int seq1[10];
    int seq2[10];
    for (int i = 0; i < 10; i++) {
        seq1[i] = generate_sequence_next(&seq_gen);
    }
    for (int i = 0; i < 10; i++) {
        seq2[i] = generate_sequence_next(&seq_gen);
    }
    SequenceAligner align_gen = {seq1, seq2, 10, 10};
    int match[10];
    int match_len;
    while (1) {
        align_sequences_next(&align_gen, match, &match_len);
        for (int i = 0; i < match_len; i++) {
            printf("%d ", match[i]);
        }
        printf("\n");
    }
}