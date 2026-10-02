c
#include <stdio.h>
#include <stdlib.h>

typedef struct TemporalFrame {
    int value;
    struct TemporalFrame *next;
} TemporalFrame;

typedef struct FrameSequence {
    TemporalFrame *head;
    TemporalFrame *tail;
} FrameSequence;

void FrameSequence_init(FrameSequence *sequence) {
    sequence->head = NULL;
    sequence->tail = NULL;
}

void FrameSequence_append(FrameSequence *sequence, int value) {
    TemporalFrame *new_frame = (TemporalFrame *)malloc(sizeof(TemporalFrame));
    new_frame->value = value;
    new_frame->next = NULL;
    if (sequence->tail) {
        sequence->tail->next = new_frame;
    } else {
        sequence->head = new_frame;
    }
    sequence->tail = new_frame;
}

TemporalFrame *FrameSequence_traverse(FrameSequence *sequence) {
    return sequence->head;
}

void update_frames(FrameSequence *sequence, void (*updater)(int)) {
    TemporalFrame *current = FrameSequence_traverse(sequence);
    while (current) {
        updater(current->value);
        current = current->next;
    }
}

void updater(int value) {
    printf("%d ", value);
    if (value % 2 == 0) {
        FrameSequence_append(sequence, value + 10);
    }
}

FrameSequence sequence;

int main() {
    FrameSequence_init(&sequence);
    for (int i = 0; i < 10; i++) {
        FrameSequence_append(&sequence, i);
    }

    while (1) {
        update_frames(&sequence, updater);
    }

    return 0;
}