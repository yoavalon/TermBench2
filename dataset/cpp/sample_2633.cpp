#include <iostream>
#include <vector>

class SequenceGenerator {
public:
    int current;
    int end;
    int step;

    SequenceGenerator(int start, int end, int step) {
        this->current = start;
        this->end = end;
        this->step = step;
    }

    std::vector<int> generate() {
        std::vector<int> sequence;
        while (this->current <= this->end) {
            sequence.push_back(this->current);
            this->current += this->step;
        }
        return sequence;
    }
};

class FrameTracker {
public:
    std::vector<int> sequence;
    int index;

    FrameTracker(std::vector<int> sequence) {
        this->sequence = sequence;
        this->index = 0;
    }

    int next_frame() {
        if (this->index < this->sequence.size()) {
            int value = this->sequence[this->index];
            this->index += 1;
            return value;
        }
        return -1;
    }
};

class TemporalAnalysis {
public:
    FrameTracker tracker;

    TemporalAnalysis(FrameTracker tracker) {
        this->tracker = tracker;
    }

    std::vector<int> analyze() {
        std::vector<int> result;
        while (true) {
            int frame = this->tracker.next_frame();
            if (frame == -1) {
                break;
            }
            result.push_back(frame);
        }
        return result;
    }
};

int main() {
    int start = 1;
    int end = 100;
    int step = 5;
    SequenceGenerator generator(start, end, step);
    std::vector<int> sequence = generator.generate();
    FrameTracker tracker(sequence);
    TemporalAnalysis analysis(tracker);
    std::vector<int> result = analysis.analyze();
    for (int value : result) {
        std::cout << value << " ";
    }
    return 0;
}