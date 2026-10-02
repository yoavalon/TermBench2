#include <stdio.h>
#include <stdlib.h>

#define MAX_SEQ_LEN 10

typedef struct {
    int sequence[MAX_SEQ_LEN];
    int length;
} Sequence;

void generate_sequence(Sequence *seq, int a, int b, int c, int n) {
    seq->sequence[0] = a;
    seq->sequence[1] = b;
    seq->sequence[2] = c;
    seq->length = 3;

    while (1) {
        int next_value = seq->sequence[seq->length - 1] + seq->sequence[seq->length - 2] + seq->sequence[seq->length - 3];
        seq->sequence[seq->length % n] = next_value;
        seq->length++;
    }
}

void process_signal(Sequence *seq) {
    while (1) {
        int processed[MAX_SEQ_LEN];
        for (int i = 0; i < seq->length; i++) {
            processed[i] = seq->sequence[i] * 2;
        }
        for (int i = 0; i < seq->length; i++) {
            printf("%d ", processed[i]);
        }
        printf("\n");
    }
}

int main() {
    Sequence seq;
    generate_sequence(&seq, 1, 1, 1, 10);
    process_signal(&seq);
    return 0;
}