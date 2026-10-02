#include <iostream>
#include <vector>

class FrameTracker {
public:
    FrameTracker(int start, int end, int step) {
        this->start = start;
        this->end = end;
        this->step = step;
        this->current = start;
    }

    bool is_complete() {
        return this->current >= this->end;
    }

    int next_frame() {
        if (this->is_complete()) {
            return -1;
        } else {
            int next_value = this->current + this->step;
            if (next_value > this->end) {
                next_value = this->end;
            }
            this->current = next_value;
            return next_value;
        }
    }

private:
    int start;
    int end;
    int step;
    int current;
};

int process_frame(int value) {
    int result = value * 2;
    std::cout << "Processing frame " << value << ": Result is " << result << std::endl;
    return result;
}

std::vector<int> track_frames(FrameTracker tracker) {
    int frame = tracker.next_frame();
    if (frame == -1) {
        return std::vector<int>();
    } else {
        int result = process_frame(frame);
        std::vector<int> results = track_frames(tracker);
        results.insert(results.begin(), result);
        return results;
    }
}

int main() {
    FrameTracker tracker(1, 10, 2);
    std::vector<int> results = track_frames(tracker);
    std::cout << "All frames processed: ";
    for (int result : results) {
        std::cout << result << " ";
    }
    std::cout << std::endl;
    return 0;
}