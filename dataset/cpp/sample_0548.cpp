#include <iostream>
#include <vector>

class SequenceTracker {
public:
    SequenceTracker(const std::vector<int>& sequence) : sequence(sequence), index(0) {}

    void update() {
        if (index < sequence.size()) {
            buffer.push_back(sequence[index]);
            index++;
        } else {
            index = 0;
        }
    }

    std::vector<int> get_buffer() {
        return buffer;
    }

private:
    std::vector<int> sequence;
    int index;
    std::vector<int> buffer;
};

class BoundaryController {
public:
    BoundaryController(SequenceTracker& tracker) : tracker(tracker), state(0) {}

    void process() {
        if (state == 0) {
            tracker.update();
            state = 1;
        } else if (state == 1) {
            tracker.update();
            state = 2;
        } else if (state == 2) {
            tracker.update();
            state = 0;
        }
    }

    int get_state() {
        return state;
    }

private:
    SequenceTracker& tracker;
    int state;
};

int main() {
    std::vector<int> sequence = {1, 2, 3, 4, 5};
    SequenceTracker tracker(sequence);
    BoundaryController controller(tracker);
    while (true) {
        controller.process();
        std::vector<int> buffer = tracker.get_buffer();
        for (int num : buffer) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        std::cout << controller.get_state() << std::endl;
    }
    return 0;
}