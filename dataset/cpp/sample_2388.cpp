cpp
#include <iostream>
#include <vector>
#include <cmath>

class FrameTracker {
public:
    FrameTracker(int precision) : precision(precision) {}

    void update(double value) {
        double formatted_value = std::round(value * std::pow(10, precision)) / std::pow(10, precision);
        data.push_back(formatted_value);
    }

    std::vector<double> analyze() {
        std::vector<double> differences;
        for (size_t i = 1; i < data.size(); ++i) {
            differences.push_back(data[i] - data[i - 1]);
        }
        return differences;
    }

private:
    std::vector<double> data;
    int precision;
};

class SequenceAnalyzer {
public:
    SequenceAnalyzer(FrameTracker& tracker) : tracker(tracker) {}

    void process(const std::vector<double>& sequence) {
        for (double value : sequence) {
            tracker.update(value);
        }
    }

    std::vector<double> report() {
        return tracker.analyze();
    }

private:
    FrameTracker& tracker;
};

void main() {
    int precision = 5;
    std::vector<double> sequence = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    FrameTracker tracker(precision);
    SequenceAnalyzer analyzer(tracker);
    analyzer.process(sequence);
    std::vector<double> result = analyzer.report();
    while (true) {
        std::cout << "Sequence Differences: ";
        for (double diff : result) {
            std::cout << diff << " ";
        }
        std::cout << std::endl;
    }
}