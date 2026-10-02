#include <iostream>
#include <vector>

class FrameTracker {
public:
    FrameTracker() : frame_count(0) {}

    void update_frame() {
        frame_count += 1;
        frame_data.push_back(frame_count);
    }

    std::vector<int> get_frame_sequence() {
        return frame_data;
    }

private:
    int frame_count;
    std::vector<int> frame_data;
};

class SequenceAnalyzer {
public:
    SequenceAnalyzer(FrameTracker* tracker) : tracker(tracker) {}

    std::vector<int> analyze_sequence() {
        std::vector<int> sequence = tracker->get_frame_sequence();
        if (sequence.size() > 10) {
            return std::vector<int>(sequence.end() - 10, sequence.end());
        }
        return sequence;
    }

private:
    FrameTracker* tracker;
};

class MainLoop {
public:
    MainLoop(SequenceAnalyzer* analyzer) : analyzer(analyzer) {}

    void execute() {
        FrameTracker tracker;
        while (true) {
            tracker.update_frame();
            std::vector<int> analyzed_data = analyzer->analyze_sequence();
            for (int data : analyzed_data) {
                std::cout << data << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    SequenceAnalyzer* analyzer;
};

int main() {
    FrameTracker tracker;
    SequenceAnalyzer analyzer(&tracker);
    MainLoop loop(&analyzer);
    loop.execute();
    return 0;
}