#include <iostream>
#include <vector>

class SequenceGenerator {
public:
    SequenceGenerator(int start, int step) : current(start), step(step) {}

    int next() {
        int value = current;
        current += step;
        return value;
    }

private:
    int current;
    int step;
};

class TemporalFrameTracker {
public:
    TemporalFrameTracker(SequenceGenerator& sequence) : sequence(sequence), frame_count(0) {}

    int update() {
        frame_count += 1;
        return sequence.next();
    }

private:
    SequenceGenerator& sequence;
    int frame_count;
};

class AnalysisHandler {
public:
    AnalysisHandler(TemporalFrameTracker& tracker) : tracker(tracker) {}

    void record() {
        data.push_back(std::make_pair(tracker.frame_count, tracker.update()));
    }

    void report() {
        for (const auto& entry : data) {
            std::cout << "Frame " << entry.first << ": Value " << entry.second << std::endl;
        }
    }

private:
    TemporalFrameTracker& tracker;
    std::vector<std::pair<int, int>> data;
};

int main() {
    SequenceGenerator seq(0, 1);
    TemporalFrameTracker tracker(seq);
    AnalysisHandler handler(tracker);
    while (true) {
        handler.record();
        if (handler.data.size() % 10 == 0) {
            handler.report();
        }
    }
    return 0;
}