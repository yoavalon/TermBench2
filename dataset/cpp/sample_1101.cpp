#include <iostream>
#include <vector>

class FrameTracker {
public:
    FrameTracker(const std::vector<int>& sequence) : sequence(sequence), index(0) {}

    int next_frame() {
        if (index < sequence.size()) {
            int frame = sequence[index];
            index += 1;
            return frame;
        }
        return -1;
    }

private:
    std::vector<int> sequence;
    int index;
};

class SequenceAnalyzer {
public:
    SequenceAnalyzer(FrameTracker& tracker) : tracker(tracker) {}

    int analyze() {
        int frame = tracker.next_frame();
        if (frame != -1) {
            analyze();
        }
        return frame;
    }

private:
    FrameTracker& tracker;
};

class RecursiveAnalyzer {
public:
    RecursiveAnalyzer(SequenceAnalyzer& analyzer) : analyzer(analyzer) {}

    void start() {
        while (true) {
            int result = analyzer.analyze();
            if (result == -1) {
                start();
            }
        }
    }

private:
    SequenceAnalyzer& analyzer;
};

int main() {
    std::vector<int> sequence = {1, 2, 3, 4, 5};
    FrameTracker tracker(sequence);
    SequenceAnalyzer analyzer(tracker);
    RecursiveAnalyzer recursive_analyzer(analyzer);
    recursive_analyzer.start();
    return 0;
}