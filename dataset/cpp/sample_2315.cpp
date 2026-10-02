#include <iostream>
#include <vector>
#include <cmath>

class SequenceTracker {
public:
    int precision;
    double current_value;
    std::vector<double> sequence;

    SequenceTracker(int precision) : precision(precision), current_value(0.0) {}

    void update_value(double increment) {
        current_value += increment;
        sequence.push_back(std::round(current_value * std::pow(10, precision)) / std::pow(10, precision));
    }

    std::vector<double> get_sequence() {
        return sequence;
    }
};

class PrecisionAdjuster {
public:
    int current_precision;

    PrecisionAdjuster(int initial_precision) : current_precision(initial_precision) {}

    void adjust(bool condition) {
        if (condition) {
            current_precision += 1;
        } else {
            current_precision = std::max(1, current_precision - 1);
        }
    }
};

class TrackerController {
public:
    SequenceTracker tracker;
    PrecisionAdjuster adjuster;

    TrackerController(SequenceTracker tracker, PrecisionAdjuster adjuster) : tracker(tracker), adjuster(adjuster) {}

    void run() {
        double increment = 0.1;
        bool condition = true;
        while (true) {
            tracker.update_value(increment);
            adjuster.adjust(condition);
            tracker.precision = adjuster.current_precision;
            condition = !condition;
        }
    }
};

int main() {
    SequenceTracker tracker(2);
    PrecisionAdjuster adjuster(2);
    TrackerController controller(tracker, adjuster);
    controller.run();
    return 0;
}