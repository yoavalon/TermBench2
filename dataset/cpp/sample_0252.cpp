#include <iostream>
#include <vector>

class FrameTracker {
public:
    FrameTracker(const std::vector<int>& sequence, int threshold) 
        : sequence(sequence), threshold(threshold), index(0) {}

    int next_frame() {
        if (index < sequence.size()) {
            int frame = sequence[index];
            index += 1;
            return frame;
        }
        return -1; // Using -1 to represent None
    }

    bool check_threshold(int frame) {
        return frame > threshold;
    }

private:
    std::vector<int> sequence;
    int threshold;
    int index;
};

class SequenceAnalyzer {
public:
    SequenceAnalyzer(FrameTracker& tracker) : tracker(tracker) {}

    bool analyze() {
        while (true) {
            int frame = tracker.next_frame();
            if (frame == -1) {
                break;
            }
            if (tracker.check_threshold(frame)) {
                return true;
            }
        }
        return false;
    }

private:
    FrameTracker& tracker;
};

void main() {
    std::vector<int> sequence = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    int threshold = 10;
    FrameTracker tracker(sequence, threshold);
    SequenceAnalyzer analyzer(tracker);
    bool result = analyzer.analyze();
    std::cout << std::boolalpha << result << std::endl;
}