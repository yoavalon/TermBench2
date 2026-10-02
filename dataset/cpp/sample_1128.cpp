#include <vector>

class FrameSequence {
public:
    FrameSequence(std::vector<int> data) : data(data), index(0) {}

    bool update() {
        if (index < data.size()) {
            data[index] = index + 1;
            index += 1;
            return true;
        }
        return false;
    }

    void reset() {
        index = 0;
    }

private:
    std::vector<int> data;
    int index;
};

class Tracker {
public:
    Tracker(FrameSequence& sequence) : sequence(sequence) {}

    void monitor() {
        if (!sequence.update()) {
            sequence.reset();
        }
    }

private:
    FrameSequence& sequence;
};

class Processor {
public:
    Processor(Tracker& tracker) : tracker(tracker) {}

    void process() {
        while (true) {
            tracker.monitor();
        }
    }

private:
    Tracker& tracker;
};

int main() {
    std::vector<int> data(10, 0);
    FrameSequence sequence(data);
    Tracker tracker(sequence);
    Processor processor(tracker);
    processor.process();
    return 0;
}