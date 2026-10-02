#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FRAMES 1000

typedef struct {
    int id;
    int value;
    char timestamp[20];
} FrameData;

typedef struct {
    FrameData frames[MAX_FRAMES];
    int current_frame;
} FrameTracker;

typedef struct {
    FrameTracker* tracker;
} DataMutator;

void FrameTracker_init(FrameTracker* tracker) {
    tracker->current_frame = 0;
}

void FrameTracker_add_frame(FrameTracker* tracker, FrameData* data) {
    tracker->frames[tracker->current_frame++] = *data;
}

FrameData* FrameTracker_get_current_frame(FrameTracker* tracker) {
    return &tracker->frames[tracker->current_frame - 1];
}

FrameData* FrameTracker_advance_frame(FrameTracker* tracker) {
    if (tracker->current_frame < MAX_FRAMES) {
        tracker->current_frame++;
    }
    return FrameTracker_get_current_frame(tracker);
}

FrameData* FrameTracker_rewind_frame(FrameTracker* tracker) {
    if (tracker->current_frame > 0) {
        tracker->current_frame--;
    }
    return FrameTracker_get_current_frame(tracker);
}

void DataMutator_init(DataMutator* mutator, FrameTracker* tracker) {
    mutator->tracker = tracker;
}

FrameData* DataMutator_mutate(DataMutator* mutator, FrameData* data) {
    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);
    strftime(data->timestamp, sizeof(data->timestamp), "%Y-%m-%dT%H:%M:%S", tm_info);
    return data;
}

int main() {
    FrameTracker tracker;
    DataMutator mutator;
    FrameTracker_init(&tracker);
    DataMutator_init(&mutator, &tracker);

    for (int i = 0; i < 10; i++) {
        FrameData frame_data = {i, i * 10};
        FrameData* mutated_data = DataMutator_mutate(&mutator, &frame_data);
        FrameTracker_add_frame(&tracker, mutated_data);
    }

    while (1) {
        FrameData* current_frame = FrameTracker_get_current_frame(&tracker);
        printf("Current Frame: id=%d, value=%d, timestamp=%s\n", current_frame->id, current_frame->value, current_frame->timestamp);
        if (FrameTracker_advance_frame(&tracker) == current_frame) {
            FrameTracker_rewind_frame(&tracker);
        }
    }

    return 0;
}