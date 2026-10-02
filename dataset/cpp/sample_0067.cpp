#include <iostream>
#include <vector>

int track_sequence(const std::vector<int>& frame_sequence, int boundary_condition) {
    int sequence_length = frame_sequence.size();
    for (int idx = 0; idx < sequence_length; ++idx) {
        if (frame_sequence[idx] == boundary_condition || idx == sequence_length - 1) {
            return idx;
        }
    }
    return -1;
}

int main() {
    std::vector<int> frame_sequence = {1, 2, 3, 4, 5};
    int boundary_condition = 3;
    int result = track_sequence(frame_sequence, boundary_condition);
    std::cout << result << std::endl;
    return 0;
}