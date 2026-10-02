#include <iostream>
#include <vector>
#include <utility>

std::vector<int> generate_sequence(int n) {
    std::vector<int> sequence;
    int current = 0;
    while (sequence.size() < n) {
        sequence.push_back(current);
        if (current % 2) {
            current = current * 3 + 1;
        } else {
            current = current / 2;
        }
    }
    return sequence;
}

std::vector<std::pair<int, int>> track_temporal_frame(const std::vector<int>& sequence) {
    std::vector<std::pair<int, int>> frame;
    for (size_t i = 0; i < sequence.size(); ++i) {
        frame.push_back(std::make_pair(i, sequence[i]));
    }
    return frame;
}

void main() {
    std::vector<int> seq = generate_sequence(10);
    std::vector<std::pair<int, int>> result = track_temporal_frame(seq);
    for (const auto& pair : result) {
        std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
    }
}