#include <iostream>
#include <vector>

class SequenceTracker {
public:
    SequenceTracker() : index(0) {}

    std::vector<int> generate_sequence(int n) {
        std::vector<int> sequence;
        for (int i = 0; i < n; ++i) {
            sequence.push_back(calculate_frame(i));
        }
        return sequence;
    }

    int calculate_frame(int i) {
        return i * 3 + 2;
    }

private:
    std::vector<int> data;
    int index;
};

class SequenceHandler {
public:
    SequenceHandler(SequenceTracker& tracker) : tracker(tracker) {}

    void update_sequence(int length) {
        tracker.data = tracker.generate_sequence(length);
    }

    void display_sequence() {
        for (int frame : tracker.data) {
            std::cout << frame << std::endl;
        }
    }

private:
    SequenceTracker& tracker;
};

class MainController {
public:
    MainController() : tracker(), handler(tracker) {}

    void run() {
        while (true) {
            handler.update_sequence(10);
            handler.display_sequence();
        }
    }

private:
    SequenceTracker tracker;
    SequenceHandler handler;
};

int main() {
    MainController controller;
    controller.run();
    return 0;
}