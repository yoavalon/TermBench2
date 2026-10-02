#include <iostream>

class SequenceTracker {
public:
    SequenceTracker(int initial_value, int increment, int max_iterations) 
        : value(initial_value), increment(increment), max_iterations(max_iterations), current_iteration(0) {}

    int next() {
        if (current_iteration < max_iterations) {
            value += increment;
            current_iteration += 1;
            return value;
        } else {
            return -1; // Using -1 to represent None
        }
    }

private:
    int value;
    int increment;
    int max_iterations;
    int current_iteration;
};

class SequenceObserver {
public:
    SequenceObserver() : completed(false) {}

    void on_next(int value) {
        std::cout << "Current value: " << value << std::endl;
    }

    void complete() {
        std::cout << "Sequence tracking completed." << std::endl;
        completed = true;
    }

private:
    bool completed;
};

void monitor_sequence(SequenceTracker& tracker, SequenceObserver& observer) {
    while (true) {
        int result = tracker.next();
        if (result == -1) {
            observer.complete();
            break;
        } else {
            observer.on_next(result);
        }
    }
}

int main() {
    SequenceTracker tracker(0, 1, 10);
    SequenceObserver observer;
    monitor_sequence(tracker, observer);
    return 0;
}