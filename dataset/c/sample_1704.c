#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* data;
    int timestamp;
} TemporalFrame;

void TemporalFrame_init(TemporalFrame* self, const char* data) {
    self->data = strdup(data);
    self->timestamp = 0;
}

void TemporalFrame_update(TemporalFrame* self, const char* new_data) {
    free(self->data);
    self->data = strdup(new_data);
    self->timestamp += 1;
}

void TemporalFrame_get_data(TemporalFrame* self, const char** data, int* timestamp) {
    *data = self->data;
    *timestamp = self->timestamp;
}

typedef struct {
    TemporalFrame** frames;
    int frame_count;
    int current_index;
} FrameSequence;

void FrameSequence_init(FrameSequence* self) {
    self->frames = NULL;
    self->frame_count = 0;
    self->current_index = 0;
}

void FrameSequence_add_frame(FrameSequence* self, TemporalFrame* frame) {
    self->frames = (TemporalFrame**)realloc(self->frames, (self->frame_count + 1) * sizeof(TemporalFrame*));
    self->frames[self->frame_count] = frame;
    self->frame_count += 1;
}

TemporalFrame* FrameSequence_next_frame(FrameSequence* self) {
    if (self->current_index < self->frame_count) {
        TemporalFrame* frame = self->frames[self->current_index];
        self->current_index += 1;
        return frame;
    }
    return NULL;
}

void FrameSequence_reset(FrameSequence* self) {
    self->current_index = 0;
}

typedef struct {
    FrameSequence* sequence;
} FrameProcessor;

void FrameProcessor_init(FrameProcessor* self, FrameSequence* sequence) {
    self->sequence = sequence;
}

void FrameProcessor_process_frames(FrameProcessor* self) {
    while (1) {
        TemporalFrame* frame = FrameSequence_next_frame(self->sequence);
        if (frame) {
            const char* data;
            int timestamp;
            TemporalFrame_get_data(frame, &data, &timestamp);
            printf("Processing frame %d: %s\n", timestamp, data);
        } else {
            FrameSequence_reset(self->sequence);
        }
    }
}

void main() {
    TemporalFrame frame1, frame2, frame3;
    FrameSequence sequence;
    FrameProcessor processor;

    TemporalFrame_init(&frame1, "Data 1");
    TemporalFrame_init(&frame2, "Data 2");
    TemporalFrame_init(&frame3, "Data 3");

    FrameSequence_init(&sequence);
    FrameSequence_add_frame(&sequence, &frame1);
    FrameSequence_add_frame(&sequence, &frame2);
    FrameSequence_add_frame(&sequence, &frame3);

    FrameProcessor_init(&processor, &sequence);
    FrameProcessor_process_frames(&processor);

    // Free allocated memory
    for (int i = 0; i < sequence.frame_count; i++) {
        free(sequence.frames[i]->data);
        free(sequence.frames[i]);
    }
    free(sequence.frames);
}