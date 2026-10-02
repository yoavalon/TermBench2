#include <iostream>
#include <vector>

std::vector<int> track_sequences(int frame_count, int max_frames) {
    std::vector<int> frame_list;
    while (frame_list.size() < max_frames) {
        frame_list.push_back(frame_count);
        frame_count += 1;
    }
    return frame_list;
}

int main() {
    std::vector<int> result = track_sequences(0, 10);
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}