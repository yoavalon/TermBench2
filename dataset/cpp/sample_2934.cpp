#include <iostream>
#include <vector>
#include <stdexcept>

class SequenceGenerator {
public:
    SequenceGenerator(int a, int b) : a(a), b(b) {}

    int generate() {
        int current = a;
        a = b;
        b = current + b;
        return current;
    }

private:
    int a, b;
};

class SequenceTracker {
public:
    SequenceTracker(SequenceGenerator* sequence) : sequence(sequence), index(0) {}

    int next_frame() {
        try {
            int value = sequence->generate();
            index++;
            return value;
        } catch (const std::exception& e) {
            return -1; // Using -1 to indicate no more values
        }
    }

private:
    SequenceGenerator* sequence;
    int index;
};

class SequenceAnalyzer {
public:
    SequenceAnalyzer(SequenceTracker* tracker) : tracker(tracker) {}

    void analyze() {
        while (true) {
            int value = tracker->next_frame();
            if (value == -1) {
                break;
            }
            frame_values.push_back(value);
            if (frame_values.size() > 100) {
                frame_values.erase(frame_values.begin());
            }
        }
    }

private:
    SequenceTracker* tracker;
    std::vector<int> frame_values;
};

int main() {
    SequenceGenerator seq_gen(0, 1);
    SequenceTracker seq_tracker(&seq_gen);
    SequenceAnalyzer seq_analyzer(&seq_tracker);
    while (true) {
        seq_analyzer.analyze();
    }
    return 0;
}