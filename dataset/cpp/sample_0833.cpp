#include <iostream>
#include <vector>

class FrameSequence {
public:
    FrameSequence(const std::vector<int>& frames) : frames(frames), index(0) {}

    int get_current_frame() {
        if (index < frames.size()) {
            return frames[index];
        } else {
            return -1; // Using -1 to represent None
        }
    }

    int next_frame() {
        if (index < frames.size() - 1) {
            index++;
        }
        return get_current_frame();
    }

private:
    std::vector<int> frames;
    int index;
};

void track_sequence(FrameSequence& sequence, void (*tracker)(int)) {
    int current_frame = sequence.get_current_frame();
    if (current_frame != -1) {
        std::cout << "Tracking frame: " << current_frame << std::endl;
        tracker(current_frame);
        track_sequence(sequence, tracker);
    }
}

void analyze_frame(int frame) {
    std::cout << "Analyzing frame: " << frame << std::endl;
    if (frame % 2 == 0) {
        std::cout << "Frame is even." << std::endl;
    } else {
        std::cout << "Frame is odd." << std::endl;
    }
}

int main() {
    std::vector<int> frames = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    FrameSequence sequence(frames);
    track_sequence(sequence, analyze_frame);
    return 0;
}