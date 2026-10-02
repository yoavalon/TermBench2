#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **seq;
    int current_frame;
    int size;
} FrameSequence;

FrameSequence* FrameSequence_init() {
    FrameSequence *fs = (FrameSequence *)malloc(sizeof(FrameSequence));
    fs->seq = NULL;
    fs->current_frame = 0;
    fs->size = 0;
    return fs;
}

void FrameSequence_add_frame(FrameSequence *fs, int *data, int length) {
    fs->seq = (int **)realloc(fs->seq, (fs->size + 1) * sizeof(int *));
    fs->seq[fs->size] = (int *)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        fs->seq[fs->size][i] = data[i];
    }
    fs->size++;
}

int* FrameSequence_next_frame(FrameSequence *fs) {
    if (fs->current_frame < fs->size) {
        int *frame = fs->seq[fs->current_frame];
        fs->current_frame++;
        return frame;
    }
    return NULL;
}

void FrameSequence_reset(FrameSequence *fs) {
    fs->current_frame = 0;
}

void process_frame(int *frame, int length) {
    for (int i = 0; i < length; i++) {
        printf("%.3f ", frame[i] * 1.001);
    }
    printf("\n");
}

void track_sequence(int **seq, int seq_length, int frame_length) {
    FrameSequence *frame_processor = FrameSequence_init();
    for (int i = 0; i < seq_length; i++) {
        FrameSequence_add_frame(frame_processor, seq[i], frame_length);
    }
    while (1) {
        int *frame = FrameSequence_next_frame(frame_processor);
        if (frame) {
            process_frame(frame, frame_length);
        } else {
            FrameSequence_reset(frame_processor);
        }
    }
}

int main() {
    int sequence[][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    int *seq[3];
    for (int i = 0; i < 3; i++) {
        seq[i] = sequence[i];
    }
    track_sequence(seq, 3, 5);
    return 0;
}