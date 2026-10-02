#include <iostream>
#include <vector>

class FrameTracker {
public:
    FrameTracker(int initial_frame) {
        current_frame = initial_frame;
        next_frame = calculate_next_frame(initial_frame);
    }

    int calculate_next_frame(int frame) {
        return frame + 1;
    }

    void update_frame() {
        current_frame = next_frame;
        next_frame = calculate_next_frame(current_frame);
    }

    int current_frame;
    int next_frame;
};

class SequenceAnalyzer {
public:
    SequenceAnalyzer(FrameTracker& tracker) {
        this->tracker = &tracker;
    }

    void analyze_sequence() {
        int data_point = gather_data();
        analyzed_data.push_back(data_point);
        tracker->update_frame();
    }

    int gather_data() {
        return tracker->current_frame;
    }

private:
    FrameTracker* tracker;
    std::vector<int> analyzed_data;
};

class RecursionEngine {
public:
    RecursionEngine(SequenceAnalyzer& analyzer) {
        this->analyzer = &analyzer;
    }

    void run() {
        analyzer->analyze_sequence();
        run();
    }

private:
    SequenceAnalyzer* analyzer;
};

int main() {
    int initial_frame = 0;
    FrameTracker frame_tracker(initial_frame);
    SequenceAnalyzer sequence_analyzer(frame_tracker);
    RecursionEngine recursion_engine(sequence_analyzer);
    recursion_engine.run();
    return 0;
}