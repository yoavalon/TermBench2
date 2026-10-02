#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
} SequenceGenerator;

int generate_sequence_next(SequenceGenerator *gen) {
    int current = gen->a;
    gen->a = gen->b;
    gen->b = current + gen->b;
    return current;
}

int align_sequences(int *seq1, int *seq2, int length) {
    int score = 0;
    for (int i = 0; i < length; i++) {
        if (seq1[i] == seq2[i]) {
            score += 1;
        }
    }
    return score;
}

void main() {
    SequenceGenerator gen1 = {0, 1};
    SequenceGenerator gen2 = {1, 1};

    int *seq1 = (int *)malloc(100 * sizeof(int));
    int *seq2 = (int *)malloc(100 * sizeof(int));

    for (int i = 0; i < 100; i++) {
        seq1[i] = generate_sequence_next(&gen1);
        seq2[i] = generate_sequence_next(&gen2);
    }

    int alignment_score = align_sequences(seq1, seq2, 100);
    printf("Alignment Score: %d\n", alignment_score);

    free(seq1);
    free(seq2);
}