#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class FrameSequenceTracker {
public:
    int precision;
    std::vector<std::pair<int, double>> sequence;

    FrameSequenceTracker(int precision) : precision(precision) {}

    void add_frame(int timestamp, double value) {
        sequence.push_back({timestamp, std::round(value * std::pow(10, precision)) / std::pow(10, precision)});
    }

    std::vector<double> calculate_difference() {
        std::vector<double> differences;
        for (size_t i = 1; i < sequence.size(); ++i) {
            double prev_value = sequence[i - 1].second;
            double curr_value = sequence[i].second;
            differences.push_back(std::abs(curr_value - prev_value));
        }
        return differences;
    }

    std::tuple<double, double, double> analyze() {
        std::vector<double> differences = calculate_difference();
        double max_diff = differences.empty() ? 0 : *std::max_element(differences.begin(), differences.end());
        double min_diff = differences.empty() ? 0 : *std::min_element(differences.begin(), differences.end());
        double avg_diff = differences.empty() ? 0 : std::accumulate(differences.begin(), differences.end(), 0.0) / differences.size();
        return std::make_tuple(max_diff, min_diff, avg_diff);
    }
};

void generate_sequence(FrameSequenceTracker& tracker, int start, int end, int step) {
    int timestamp = start;
    while (timestamp <= end) {
        double value = timestamp * 0.123456789;
        tracker.add_frame(timestamp, value);
        timestamp += step;
    }
}

int main() {
    FrameSequenceTracker tracker(5);
    generate_sequence(tracker, 0, 100, 1);
    auto [max_diff, min_diff, avg_diff] = tracker.analyze();
    std::cout << "Max Difference: " << max_diff << ", Min Difference: " << min_diff << ", Average Difference: " << avg_diff << std::endl;
    return 0;
}