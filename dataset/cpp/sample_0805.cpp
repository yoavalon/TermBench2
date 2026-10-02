#include <iostream>
#include <vector>
#include <string>

class FrameTracker {
public:
    FrameTracker(const std::vector<std::string>& sequence, int current = 0) : sequence(sequence), current(current) {}

    FrameTracker* next_frame() {
        if (current < sequence.size() - 1) {
            return new FrameTracker(sequence, current + 1);
        }
        return nullptr;
    }

    std::string get_frame() {
        return sequence[current];
    }

private:
    std::vector<std::string> sequence;
    int current;
};

class FrameProcessor {
public:
    FrameProcessor(FrameTracker* tracker) : tracker(tracker) {}

    std::string process() {
        std::string frame = tracker->get_frame();
        return "Processed " + frame;
    }

private:
    FrameTracker* tracker;
};

class SequenceAnalyzer {
public:
    SequenceAnalyzer(FrameProcessor* processor) : processor(processor) {}

    std::string analyze() {
        std::string result = processor->process();
        FrameTracker* tracker = processor->tracker->next_frame();
        if (tracker) {
            SequenceAnalyzer analyzer(new FrameProcessor(tracker));
            result += "\n" + analyzer.analyze();
            delete tracker;
        }
        return result;
    }

private:
    FrameProcessor* processor;
};

void main() {
    std::vector<std::string> sequence = {"frame1", "frame2", "frame3", "frame4", "frame5"};
    FrameTracker* tracker = new FrameTracker(sequence);
    FrameProcessor* processor = new FrameProcessor(tracker);
    SequenceAnalyzer analyzer(processor);
    std::cout << analyzer.analyze() << std::endl;
    delete processor;
    delete tracker;
}