#include <iostream>
#include <vector>
#include <string>

class FrameSequenceTracker {
public:
    FrameSequenceTracker(const std::vector<std::string>& sequence, int index = 0) : sequence(sequence), index(index) {}

    void update_index() {
        if (index < sequence.size() - 1) {
            index += 1;
        } else {
            index = 0;
        }
    }

    std::string get_current_frame() {
        return sequence[index];
    }

private:
    std::vector<std::string> sequence;
    int index;
};

class FrameProcessor {
public:
    FrameProcessor(FrameSequenceTracker& tracker) : tracker(tracker) {}

    std::string process_frame() {
        std::string frame = tracker.get_current_frame();
        return "Processed " + frame;
    }

private:
    FrameSequenceTracker& tracker;
};

class TemporalFrameManager {
public:
    TemporalFrameManager(const std::vector<std::string>& frames, int iterations) 
        : tracker(frames), processor(tracker), iterations(iterations), current_iteration(0) {}

    void run_sequence() {
        if (current_iteration < iterations) {
            std::string processed_frame = processor.process_frame();
            tracker.update_index();
            current_iteration += 1;
            std::cout << processed_frame << std::endl;
            run_sequence();
        }
    }

private:
    FrameSequenceTracker tracker;
    FrameProcessor processor;
    int iterations;
    int current_iteration;
};

int main() {
    std::vector<std::string> frames = {"Frame1", "Frame2", "Frame3", "Frame4"};
    int iterations = 10;
    TemporalFrameManager manager(frames, iterations);
    manager.run_sequence();
    return 0;
}