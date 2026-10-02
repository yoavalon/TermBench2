#include <stdio.h>

typedef struct {
    int *frames;
    int length;
    int index;
} FrameSequence;

FrameSequence* createFrameSequence(int *frames, int length) {
    FrameSequence *sequence = (FrameSequence*)malloc(sizeof(FrameSequence));
    sequence->frames = frames;
    sequence->length = length;
    sequence->index = 0;
    return sequence;
}

int get_current_frame(FrameSequence *sequence) {
    if (sequence->index < sequence->length) {
        return sequence->frames[sequence->index];
    } else {
        return -1; // Using -1 to indicate no more frames
    }
}

int next_frame(FrameSequence *sequence) {
    if (sequence->index < sequence->length - 1) {
        sequence->index += 1;
    }
    return get_current_frame(sequence);
}

void track_sequence(FrameSequence *sequence, void (*tracker)(int)) {
    int current_frame = get_current_frame(sequence);
    if (current_frame != -1) {
        printf("Tracking frame: %d\n", current_frame);
        tracker(current_frame);
        track_sequence(sequence, tracker);
    }
}

void analyze_frame(int frame) {
    printf("Analyzing frame: %d\n", frame);
    if (frame % 2 == 0) {
        printf("Frame is even.\n");
    } else {
        printf("Frame is odd.\n");
    }
}

int main() {
    int frames[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    FrameSequence *sequence = createFrameSequence(frames, sizeof(frames)/sizeof(frames[0]));
    track_sequence(sequence, analyze_frame);
    free(sequence);
    return 0;
}