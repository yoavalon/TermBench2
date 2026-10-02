#include <iostream>
#include <vector>

class FrameSequence {
public:
    std::vector<std::vector<int>> seq;
    int current_frame = 0;

    void add_frame(const std::vector<int>& data) {
        seq.push_back(data);
    }

    std::vector<int> next_frame() {
        if (current_frame < seq.size()) {
            current_frame += 1;
            return seq[current_frame - 1];
        }
        return {};
    }

    void reset() {
        current_frame = 0;
    }
};

std::vector<double> process_frame(const std::vector<int>& frame) {
    std::vector<double> processed_data;
    for (int x : frame) {
        processed_data.push_back(x * 1.001);
    }
    return processed_data;
}

void track_sequence(const std::vector<std::vector<int>>& seq) {
    FrameSequence frame_processor;
    for (const auto& frame : seq) {
        frame_processor.add_frame(frame);
    }
    while (true) {
        std::vector<int> frame = frame_processor.next_frame();
        if (!frame.empty()) {
            std::vector<double> processed_frame = process_frame(frame);
            for (double x : processed_frame) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
        } else {
            frame_processor.reset();
        }
    }
}

int main() {
    std::vector<std::vector<int>> sequence = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    track_sequence(sequence);
    return 0;
}