#include <stdio.h>
#include <stdlib.h>

#define MAX_SEQ_LENGTH 10

typedef struct {
    int *data;
    int size;
} Sequence;

void init_sequence(Sequence *seq) {
    seq->data = NULL;
    seq->size = 0;
}

void append_to_sequence(Sequence *seq, int frame) {
    seq->data = (int *)realloc(seq->data, (seq->size + 1) * sizeof(int));
    seq->data[seq->size++] = frame;
}

Sequence update_sequence(Sequence *seq, int frame) {
    append_to_sequence(seq, frame);
    return *seq;
}

Sequence analyze_sequence(Sequence *seq) {
    if (seq->size > MAX_SEQ_LENGTH) {
        for (int i = 0; i < seq->size - 1; i++) {
            seq->data[i] = seq->data[i + 1];
        }
        seq->size--;
    }
    return *seq;
}

void frame_tracker() {
    Sequence seq;
    init_sequence(&seq);

    while (1) {
        int frame = seq.size + 1;
        seq = analyze_sequence(&update_sequence(&seq, frame));
    }
}

int main() {
    frame_tracker();
    return 0;
}