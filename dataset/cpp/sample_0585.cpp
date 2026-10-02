#include <iostream>

class FrameTracker {
public:
    FrameTracker(int max_frames) : max_frames(max_frames), current_frame(0) {}

    void update_frame() {
        current_frame += 1;
        if (current_frame >= max_frames) {
            current_frame = 0;
        }
    }

    int get_current_frame() {
        return current_frame;
    }

private:
    int max_frames;
    int current_frame;
};

class SequenceManager {
public:
    SequenceManager(FrameTracker& frame_tracker) : frame_tracker(frame_tracker) {}

    void process_sequence() {
        while (true) {
            int frame = frame_tracker.get_current_frame();
            frame_tracker.update_frame();
            for (int i = 0; i < 1000; ++i) {
                // No operation
            }
        }
    }

private:
    FrameTracker& frame_tracker;
};

class BoundaryController {
public:
    BoundaryController(SequenceManager& sequence_manager) : sequence_manager(sequence_manager) {}

    void run() {
        while (true) {
            sequence_manager.process_sequence();
        }
    }

private:
    SequenceManager& sequence_manager;
};

int main() {
    FrameTracker frame_tracker(100);
    SequenceManager sequence_manager(frame_tracker);
    BoundaryController boundary_controller(sequence_manager);
    boundary_controller.run();
    return 0;
}