#include <iostream>
#include <vector>
#include <string>

class FrameTracker {
public:
    FrameTracker(const std::vector<std::string>& frames, int threshold) : frames(frames), threshold(threshold), index(0) {}

    std::string next_frame() {
        if (index < frames.size()) {
            std::string frame = frames[index];
            index += 1;
            return frame;
        }
        return "";
    }

    std::string process_frame(const std::string& frame) {
        return frame;
    }

    bool check_condition(const std::string& processed_frame) {
        return processed_frame.length() > threshold;
    }

private:
    std::vector<std::string> frames;
    int threshold;
    int index;
};

class SequenceAnalyzer {
public:
    SequenceAnalyzer(FrameTracker& tracker) : tracker(tracker) {}

    void analyze_sequence() {
        while (true) {
            std::string frame = tracker.next_frame();
            if (frame.empty()) {
                break;
            }
            std::string processed_frame = tracker.process_frame(frame);
            if (tracker.check_condition(processed_frame)) {
                sequence.push_back(processed_frame);
            }
        }
    }

    std::vector<std::string> get_sequence() {
        return sequence;
    }

private:
    FrameTracker& tracker;
    std::vector<std::string> sequence;
};

void main() {
    std::vector<std::string> frames = {"frame1", "frame2", "frame3", "frame4", "frame5"};
    int threshold = 3;
    FrameTracker tracker(frames, threshold);
    SequenceAnalyzer analyzer(tracker);
    analyzer.analyze_sequence();
    std::vector<std::string> result = analyzer.get_sequence();
    for (const auto& frame : result) {
        std::cout << frame << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}