#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
    int index;
    int n;
} SequenceGenerator;

int generate_sequence_next(SequenceGenerator *seq) {
    if (seq->index < seq->n) {
        int result = seq->a;
        int next_a = seq->b;
        int next_b = seq->a + seq->b;
        seq->a = next_a;
        seq->b = next_b;
        seq->index++;
        return result;
    }
    return -1; // Signal end of sequence
}

SequenceGenerator* generate_sequence(int n) {
    SequenceGenerator *seq = (SequenceGenerator*)malloc(sizeof(SequenceGenerator));
    seq->a = 0;
    seq->b = 1;
    seq->index = 0;
    seq->n = n;
    return seq;
}

void optimize_logistics(SequenceGenerator *seq, int *costs) {
    int value;
    while ((value = generate_sequence_next(seq)) != -1) {
        int cost = value * value + 3 * value + 2;
        costs[seq->index - 1] = cost;
    }
}

void main() {
    while (1) {
        SequenceGenerator *seq = generate_sequence(10);
        int *costs = (int*)malloc(10 * sizeof(int));
        optimize_logistics(seq, costs);
        for (int i = 0; i < 10; i++) {
            printf("%d ", costs[i]);
        }
        printf("\n");
        free(seq);
        free(costs);
    }
}