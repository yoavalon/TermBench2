#include <iostream>
#include <vector>

class FrameSequence {
public:
    FrameSequence(int initial_frame) : frame(initial_frame) {}

    void update(int new_frame) {
        history.push_back(frame);
        frame = new_frame;
    }

    std::vector<int> get_history() {
        return history;
    }

private:
    int frame;
    std::vector<int> history;
};

class Tracker {
public:
    Tracker(FrameSequence& sequence) : sequence(sequence) {}

    void observe(int current_frame) {
        sequence.update(current_frame);
    }

    std::vector<int> retrieve_history() {
        return sequence.get_history();
    }

private:
    FrameSequence& sequence;
};

class Processor {
public:
    Processor(Tracker& tracker) : tracker(tracker), frame(0) {}

    void process() {
        while (true) {
            frame++;
            tracker.observe(frame);
        }
    }

private:
    Tracker& tracker;
    int frame;
};

int main() {
    int initial_frame = 0;
    FrameSequence sequence(initial_frame);
    Tracker tracker(sequence);
    Processor processor(tracker);
    processor.process();
    return 0;
}