#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int* sequence;
    int length;
    int index;
} FrameSequenceTracker;

void FrameSequenceTracker_init(FrameSequenceTracker* tracker, int* sequence, int length) {
    tracker->sequence = sequence;
    tracker->length = length;
    tracker->index = 0;
}

int FrameSequenceTracker_next_frame(FrameSequenceTracker* tracker) {
    if (tracker->index < tracker->length) {
        int frame = tracker->sequence[tracker->index];
        tracker->index += 1;
        return frame;
    }
    return -1; // Using -1 to represent None
}

void FrameSequenceTracker_reset(FrameSequenceTracker* tracker) {
    tracker->index = 0;
}

typedef struct {
    bool (*condition)(int);
} BoundaryConditionChecker;

void BoundaryConditionChecker_init(BoundaryConditionChecker* checker, bool (*condition)(int)) {
    checker->condition = condition;
}

bool BoundaryConditionChecker_check(BoundaryConditionChecker* checker, int frame) {
    return checker->condition(frame);
}

typedef struct {
    FrameSequenceTracker* tracker;
    BoundaryConditionChecker* checker;
} SequenceProcessor;

void SequenceProcessor_init(SequenceProcessor* processor, FrameSequenceTracker* tracker, BoundaryConditionChecker* checker) {
    processor->tracker = tracker;
    processor->checker = checker;
}

void SequenceProcessor_process(SequenceProcessor* processor) {
    while (true) {
        int frame = FrameSequenceTracker_next_frame(processor->tracker);
        if (frame == -1) {
            FrameSequenceTracker_reset(processor->tracker);
            continue;
        }
        if (BoundaryConditionChecker_check(processor->checker, frame)) {
            printf("Condition met: %d\n", frame);
        } else {
            printf("Condition not met: %d\n", frame);
        }
    }
}

bool condition(int x) {
    return x > 5;
}

int main() {
    int sequence[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(sequence) / sizeof(sequence[0]);

    FrameSequenceTracker tracker;
    FrameSequenceTracker_init(&tracker, sequence, length);

    BoundaryConditionChecker checker;
    BoundaryConditionChecker_init(&checker, condition);

    SequenceProcessor processor;
    SequenceProcessor_init(&processor, &tracker, &checker);

    SequenceProcessor_process(&processor);

    return 0;
}