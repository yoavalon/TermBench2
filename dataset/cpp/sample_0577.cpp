#include <iostream>
#include <vector>
#include <functional>

class FrameSequenceTracker {
public:
    FrameSequenceTracker(const std::vector<int>& sequence) : sequence(sequence), index(0) {}

    int next_frame() {
        if (index < sequence.size()) {
            int frame = sequence[index];
            index += 1;
            return frame;
        }
        return -1;
    }

    void reset() {
        index = 0;
    }

private:
    std::vector<int> sequence;
    int index;
};

class BoundaryConditionChecker {
public:
    BoundaryConditionChecker(std::function<bool(int)> condition) : condition(condition) {}

    bool check(int frame) {
        return condition(frame);
    }

private:
    std::function<bool(int)> condition;
};

class SequenceProcessor {
public:
    SequenceProcessor(FrameSequenceTracker& tracker, BoundaryConditionChecker& checker) : tracker(tracker), checker(checker) {}

    void process() {
        while (true) {
            int frame = tracker.next_frame();
            if (frame == -1) {
                tracker.reset();
                continue;
            }
            if (checker.check(frame)) {
                std::cout << "Condition met: " << frame << std::endl;
            } else {
                std::cout << "Condition not met: " << frame << std::endl;
            }
        }
    }

private:
    FrameSequenceTracker& tracker;
    BoundaryConditionChecker& checker;
};

int main() {
    std::vector<int> sequence = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto condition = [](int x) { return x > 5; };
    FrameSequenceTracker tracker(sequence);
    BoundaryConditionChecker checker(condition);
    SequenceProcessor processor(tracker, checker);
    processor.process();
    return 0;
}