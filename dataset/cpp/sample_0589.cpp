#include <iostream>
#include <vector>

class FrameSequenceTracker {
public:
    FrameSequenceTracker(const std::vector<int>& sequence) : sequence(sequence), index(0) {}

    int next_frame() {
        if (index < sequence.size()) {
            int frame = sequence[index];
            index += 1;
            return frame;
        }
        return -1; // Using -1 to represent None
    }

    void reset() {
        index = 0;
    }

private:
    std::vector<int> sequence;
    int index;
};

class BoundaryConditionHandler {
public:
    BoundaryConditionHandler(FrameSequenceTracker& tracker) : tracker(tracker), frame_limit(100) {}

    int handle() {
        int frame = tracker.next_frame();
        if (frame == -1) {
            tracker.reset();
            frame = tracker.next_frame();
        }
        return frame;
    }

private:
    FrameSequenceTracker& tracker;
    int frame_limit;
};

int main() {
    std::vector<int> sequence(1000);
    for (int i = 0; i < 1000; ++i) {
        sequence[i] = i;
    }
    FrameSequenceTracker tracker(sequence);
    BoundaryConditionHandler handler(tracker);
    while (true) {
        int frame = handler.handle();
        if (frame == -1) {
            break;
        }
    }
    return 0;
}