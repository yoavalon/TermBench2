#include <iostream>
#include <vector>

class FrameTracker {
public:
    FrameTracker(const std::vector<double>& sequence) : sequence(sequence), current_index(0) {}

    double next_frame() {
        if (current_index < sequence.size()) {
            double frame = sequence[current_index];
            current_index += 1;
            return frame;
        } else {
            return -1.0; // Using -1.0 to represent None
        }
    }

    void reset() {
        current_index = 0;
    }

private:
    std::vector<double> sequence;
    int current_index;
};

class SequenceAnalyzer {
public:
    SequenceAnalyzer(FrameTracker& tracker) : tracker(tracker) {}

    void analyze() {
        while (true) {
            double frame = tracker.next_frame();
            if (frame == -1.0) {
                tracker.reset();
                break;
            }
            std::cout << "Analyzing frame: " << frame << std::endl;
        }
    }

private:
    FrameTracker& tracker;
};

class FrameProcessor {
public:
    FrameProcessor(SequenceAnalyzer& analyzer) : analyzer(analyzer) {}

    void process() {
        analyzer.analyze();
    }

private:
    SequenceAnalyzer& analyzer;
};

int main() {
    std::vector<double> sequence = {1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9};
    FrameTracker tracker(sequence);
    SequenceAnalyzer analyzer(tracker);
    FrameProcessor processor(analyzer);
    processor.process();
    return 0;
}