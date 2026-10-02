#include <iostream>
#include <vector>
#include <cmath>

class SequenceTracker {
public:
    SequenceTracker(int precision) : precision(precision), current_value(0.0) {}

    void update_value(double increment) {
        current_value += increment;
        sequence.push_back(round(current_value * pow(10, precision)) / pow(10, precision));
    }

    std::vector<double> get_sequence() {
        return sequence;
    }

private:
    int precision;
    double current_value;
    std::vector<double> sequence;
};

class PrecisionManager {
public:
    PrecisionManager(int max_precision) : max_precision(max_precision), current_precision(0) {}

    void increment_precision() {
        if (current_precision < max_precision) {
            current_precision += 1;
        }
    }

    int get_precision() {
        return current_precision;
    }

private:
    int max_precision;
    int current_precision;
};

class Controller {
public:
    Controller(SequenceTracker& sequence_tracker, PrecisionManager& precision_manager)
        : sequence_tracker(sequence_tracker), precision_manager(precision_manager) {}

    void run() {
        double increment = 0.1;
        while (true) {
            sequence_tracker.update_value(increment);
            precision_manager.increment_precision();
            int precision = precision_manager.get_precision();
            sequence_tracker.precision = precision;
            std::vector<double> seq = sequence_tracker.get_sequence();
            for (double val : seq) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    SequenceTracker& sequence_tracker;
    PrecisionManager& precision_manager;
};

int main() {
    PrecisionManager precision_manager(5);
    SequenceTracker sequence_tracker(0);
    Controller controller(sequence_tracker, precision_manager);
    controller.run();
    return 0;
}