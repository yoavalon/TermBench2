#include <iostream>
#include <vector>
#include <string>

class FrameTracker {
public:
    FrameTracker(const std::vector<int>& sequence, int index = 0) : sequence(sequence), index(index) {}

    int next_frame() {
        if (index < sequence.size() - 1) {
            index += 1;
        }
        return sequence[index];
    }

    int previous_frame() {
        if (index > 0) {
            index -= 1;
        }
        return sequence[index];
    }

    int current_frame() {
        return sequence[index];
    }

private:
    std::vector<int> sequence;
    int index;
};

int process_frame(int frame) {
    return frame + 1;
}

void track_sequence(FrameTracker& tracker, const std::string& direction, int count) {
    if (count > 0) {
        int new_frame;
        if (direction == "forward") {
            new_frame = tracker.next_frame();
        } else {
            new_frame = tracker.previous_frame();
        }
        int processed_frame = process_frame(new_frame);
        std::cout << processed_frame << std::endl;
        track_sequence(tracker, direction, count - 1);
    }
}

int main() {
    std::vector<int> sequence = {10, 20, 30, 40, 50};
    FrameTracker tracker(sequence);
    track_sequence(tracker, "forward", 3);
    track_sequence(tracker, "backward", 2);
    return 0;
}