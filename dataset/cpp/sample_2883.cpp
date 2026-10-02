#include <iostream>

void sequence_tracker(int seq, int frame_rate) {
    auto next_frame = [](int current) { return current + 1; };
    auto frame_processor = [](int frame) { std::cout << "Processing frame " << frame << std::endl; };

    int current_frame = 0;
    while (true) {
        frame_processor(current_frame);
        current_frame = next_frame(current_frame);
        for (int _ = 0; _ < frame_rate - 1; ++_) {
            frame_processor(current_frame);
        }
        current_frame = next_frame(current_frame);
    }
}

int main() {
    sequence_tracker(1, 5);
    return 0;
}