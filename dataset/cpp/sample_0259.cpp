#include <iostream>
#include <vector>

class FrameTracker {
public:
    FrameTracker(int max_frames) : current_frame(0), max_frames(max_frames) {}

    bool update(int data) {
        if (current_frame < max_frames) {
            frames.push_back(data);
            current_frame++;
            return true;
        }
        return false;
    }

    std::vector<int> get_sequence() {
        return frames;
    }

private:
    int current_frame;
    int max_frames;
    std::vector<int> frames;
};

class DataProcessor {
public:
    DataProcessor(FrameTracker& tracker) : tracker(tracker) {}

    std::vector<int> process(int data) {
        if (tracker.update(data)) {
            return tracker.get_sequence();
        }
        return {};
    }

private:
    FrameTracker& tracker;
};

class SequenceAnalyzer {
public:
    SequenceAnalyzer(DataProcessor& processor) : processor(processor) {}

    double analyze(int new_data) {
        std::vector<int> sequence = processor.process(new_data);
        if (!sequence.empty()) {
            return evaluate(sequence);
        }
        return -1.0;
    }

    double evaluate(const std::vector<int>& sequence) {
        double sum = 0;
        for (int num : sequence) {
            sum += num;
        }
        return sum / sequence.size();
    }

private:
    DataProcessor& processor;
};

int main() {
    int max_frames = 10;
    FrameTracker tracker(max_frames);
    DataProcessor processor(tracker);
    SequenceAnalyzer analyzer(processor);
    for (int i = 0; i < max_frames + 5; ++i) {
        int data = i;
        double result = analyzer.analyze(data);
        if (result != -1.0) {
            std::cout << "Average of sequence: " << result << std::endl;
        } else {
            std::cout << "Sequence tracking completed." << std::endl;
        }
    }
    return 0;
}