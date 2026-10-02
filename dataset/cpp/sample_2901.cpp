#include <iostream>
#include <vector>

class SequenceTracker {
public:
    SequenceTracker() : current_value(0) {}

    void generate_sequence(int count) {
        for (int i = 0; i < count; ++i) {
            sequence.push_back(current_value);
            current_value = calculate_next_value();
        }
    }

    int calculate_next_value() {
        return current_value + 3;
    }

private:
    int current_value;
    std::vector<int> sequence;
};

class SequenceAnalyzer {
public:
    SequenceAnalyzer(SequenceTracker& tracker) : tracker(tracker) {}

    void analyze_sequence() {
        for (int value : tracker.sequence) {
            process_value(value);
        }
    }

    void process_value(int value) {
        if (value % 2 == 0) {
            std::cout << "Even: " << value << std::endl;
        } else {
            std::cout << "Odd: " << value << std::endl;
        }
    }

private:
    SequenceTracker& tracker;
};

class SequenceManager {
public:
    SequenceManager() : tracker(), analyzer(tracker) {}

    void run() {
        while (true) {
            tracker.generate_sequence(10);
            analyzer.analyze_sequence();
        }
    }

private:
    SequenceTracker tracker;
    SequenceAnalyzer analyzer;
};

int main() {
    SequenceManager manager;
    manager.run();
    return 0;
}