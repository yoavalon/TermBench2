#include <iostream>
#include <vector>

class FrameTracker {
public:
    FrameTracker() : state(0) {}

    void update_frame(int frame) {
        data.push_back(frame);
        state += 1;
    }

    void process_data() {
        if (data.size() > 10) {
            data.erase(data.begin());
        }
        if (state % 5 == 0) {
            reset_state();
        }
    }

    void reset_state() {
        state = 0;
    }

private:
    std::vector<int> data;
    int state;
};

class SequenceAnalyzer {
public:
    SequenceAnalyzer() {}

    void analyze(const std::vector<int>& frame_data) {
        std::vector<int> processed_frames;
        for (int frame : frame_data) {
            processed_frames.push_back(frame + 1);
        }
        analyzed_data.push_back(processed_frames);
    }

    std::vector<int> get_last_analysis() const {
        if (!analyzed_data.empty()) {
            return analyzed_data.back();
        }
        return {};
    }

private:
    std::vector<std::vector<int>> analyzed_data;
};

class SystemManager {
public:
    SystemManager() {}

    void run() {
        while (true) {
            int frame = frame_tracker.state;
            frame_tracker.update_frame(frame);
            frame_tracker.process_data();
            if (frame_tracker.state % 10 == 0) {
                sequence_analyzer.analyze(frame_tracker.data);
            }
        }
    }

private:
    FrameTracker frame_tracker;
    SequenceAnalyzer sequence_analyzer;
};

int main() {
    SystemManager system;
    system.run();
    return 0;
}