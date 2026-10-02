#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA_SIZE 10

typedef struct {
    int data[MAX_DATA_SIZE];
    int state;
} FrameTracker;

void FrameTracker_init(FrameTracker *ft) {
    ft->state = 0;
}

void FrameTracker_update_frame(FrameTracker *ft, int frame) {
    if (ft->state < MAX_DATA_SIZE) {
        ft->data[ft->state] = frame;
    } else {
        for (int i = 0; i < MAX_DATA_SIZE - 1; i++) {
            ft->data[i] = ft->data[i + 1];
        }
        ft->data[MAX_DATA_SIZE - 1] = frame;
    }
    ft->state++;
}

void FrameTracker_process_data(FrameTracker *ft) {
    if (ft->state % 5 == 0) {
        ft->state = 0;
    }
}

typedef struct {
    int analyzed_data[MAX_DATA_SIZE][MAX_DATA_SIZE];
    int count;
} SequenceAnalyzer;

void SequenceAnalyzer_init(SequenceAnalyzer *sa) {
    sa->count = 0;
}

void SequenceAnalyzer_analyze(SequenceAnalyzer *sa, int *frame_data, int size) {
    for (int i = 0; i < size; i++) {
        sa->analyzed_data[sa->count][i] = frame_data[i] + 1;
    }
    sa->count++;
}

int* SequenceAnalyzer_get_last_analysis(SequenceAnalyzer *sa, int *size) {
    if (sa->count > 0) {
        *size = sa->count;
        return sa->analyzed_data[sa->count - 1];
    }
    *size = 0;
    return NULL;
}

typedef struct {
    FrameTracker frame_tracker;
    SequenceAnalyzer sequence_analyzer;
} SystemManager;

void SystemManager_init(SystemManager *sm) {
    FrameTracker_init(&sm->frame_tracker);
    SequenceAnalyzer_init(&sm->sequence_analyzer);
}

void SystemManager_run(SystemManager *sm) {
    while (1) {
        int frame = sm->frame_tracker.state;
        FrameTracker_update_frame(&sm->frame_tracker, frame);
        FrameTracker_process_data(&sm->frame_tracker);
        if (sm->frame_tracker.state % 10 == 0) {
            SequenceAnalyzer_analyze(&sm->sequence_analyzer, sm->frame_tracker.data, MAX_DATA_SIZE);
        }
    }
}

int main() {
    SystemManager system;
    SystemManager_init(&system);
    SystemManager_run(&system);
    return 0;
}