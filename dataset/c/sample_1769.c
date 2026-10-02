#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FRAMES 100

typedef struct {
    char* frames[MAX_FRAMES];
    int current_index;
} FrameSequence;

void FrameSequence_init(FrameSequence* self) {
    self->current_index = 0;
}

void FrameSequence_add_frame(FrameSequence* self, const char* data) {
    self->frames[self->current_index] = strdup(data);
    self->current_index++;
}

char* FrameSequence_get_current_frame(FrameSequence* self) {
    return self->frames[self->current_index - 1];
}

void FrameSequence_advance_frame(FrameSequence* self) {
    if (self->current_index < MAX_FRAMES - 1) {
        self->current_index++;
    }
}

typedef struct {
    FrameSequence* sequence;
} FrameProcessor;

void FrameProcessor_init(FrameProcessor* self, FrameSequence* sequence) {
    self->sequence = sequence;
}

void FrameProcessor_process(FrameProcessor* self) {
    while (1) {
        char* frame = FrameSequence_get_current_frame(self->sequence);
        char* processed_data = self->modify_frame(frame);
        printf("%s\n", processed_data);
        FrameSequence_advance_frame(self->sequence);
    }
}

char* FrameProcessor_modify_frame(FrameProcessor* self, const char* frame) {
    char* upper_frame = strdup(frame);
    for (int i = 0; upper_frame[i]; i++) {
        upper_frame[i] = toupper(upper_frame[i]);
    }
    return upper_frame;
}

typedef struct {
    FrameSequence frame_sequence;
    FrameProcessor frame_processor;
} DataHandler;

void DataHandler_init(DataHandler* self) {
    FrameSequence_init(&self->frame_sequence);
    FrameProcessor_init(&self->frame_processor, &self->frame_sequence);
}

void DataHandler_load_data(DataHandler* self) {
    FrameSequence_add_frame(&self->frame_sequence, "frame1");
    FrameSequence_add_frame(&self->frame_sequence, "frame2");
    FrameSequence_add_frame(&self->frame_sequence, "frame3");
}

void DataHandler_start_processing(DataHandler* self) {
    FrameProcessor_process(&self->frame_processor);
}

int main() {
    DataHandler handler;
    DataHandler_init(&handler);
    DataHandler_load_data(&handler);
    DataHandler_start_processing(&handler);
    return 0;
}