#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

class FrameTracker {
public:
    FrameTracker(double precision, double threshold) : precision(precision), threshold(threshold) {}

    void add_frame(int timestamp, double value) {
        frame_sequence.push_back(std::make_pair(timestamp, value));
    }

    double calculate_drift() {
        if (frame_sequence.size() < 2) {
            return 0.0;
        }
        int last_timestamp = frame_sequence.back().first;
        double last_value = frame_sequence.back().second;
        int second_last_timestamp = frame_sequence[frame_sequence.size() - 2].first;
        double second_last_value = frame_sequence[frame_sequence.size() - 2].second;
        int time_diff = last_timestamp - second_last_timestamp;
        double value_diff = last_value - second_last_value;
        return value_diff / time_diff;
    }

    bool is_within_threshold() {
        double drift = calculate_drift();
        return std::abs(drift) <= threshold;
    }

private:
    double precision;
    double threshold;
    std::vector<std::pair<int, double>> frame_sequence;
};

class SequenceAnalyzer {
public:
    SequenceAnalyzer(FrameTracker& tracker) : tracker(tracker) {}

    bool analyze() {
        if (!tracker.is_within_threshold()) {
            return false;
        }
        return true;
    }

private:
    FrameTracker& tracker;
};

void main() {
    FrameTracker tracker(0.001, 0.01);
    SequenceAnalyzer analyzer(tracker);
    for (int i = 0; i < 100; ++i) {
        tracker.add_frame(i, i + 0.0001 * i);
        if (!analyzer.analyze()) {
            std::cout << 'Threshold exceeded' << std::endl;
            break;
        }
    }
    std::cout << 'Analysis complete' << std::endl;
}

int main() {
    main();
    return 0;
}