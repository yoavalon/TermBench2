#include <iostream>
#include <vector>

std::vector<int> process_sequence(const std::vector<int>& seq) {
    std::vector<int> result;
    for (int i = 0; i < seq.size(); ++i) {
        if (i % 2 == 0) {
            result.push_back(seq[i] + 1);
        } else {
            result.push_back(seq[i] - 1);
        }
    }
    return result;
}

std::vector<int> track_temporal_frame(const std::vector<int>& frame) {
    std::vector<int> mutated_frame = process_sequence(frame);
    return mutated_frame;
}

int main() {
    std::vector<int> initial_frame = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> final_frame = track_temporal_frame(initial_frame);
    for (int num : final_frame) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}