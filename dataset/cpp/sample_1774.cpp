#include <cmath>

class SequenceTracker {
public:
    SequenceTracker(int start, int step) : current(start), step(step) {}

    void advance() {
        current += step;
    }

    int get_value() {
        return current;
    }

private:
    int current;
    int step;
};

class SequenceAnalyzer {
public:
    SequenceAnalyzer(SequenceTracker* tracker) : tracker(tracker) {}

    void analyze() {
        int value = tracker->get_value();
        if (value > 1000) {
            tracker->step = -tracker->step;
        } else if (value < -1000) {
            tracker->step = -tracker->step;
        }
    }

private:
    SequenceTracker* tracker;
};

class SequenceController {
public:
    SequenceController(SequenceTracker* tracker, SequenceAnalyzer* analyzer) : tracker(tracker), analyzer(analyzer) {}

    void run() {
        while (true) {
            analyzer->analyze();
            tracker->advance();
        }
    }

private:
    SequenceTracker* tracker;
    SequenceAnalyzer* analyzer;
};

int main() {
    SequenceTracker tracker(0, 10);
    SequenceAnalyzer analyzer(&tracker);
    SequenceController controller(&tracker, &analyzer);
    controller.run();
    return 0;
}