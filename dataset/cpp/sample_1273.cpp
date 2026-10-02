#include <iostream>
#include <vector>

std::vector<int> sequence_tracker(int frame_count, int max_frames) {
    std::vector<int> frame_list;
    for (int i = 0; i < frame_count; ++i) {
        frame_list.push_back(i);
        if (frame_list.size() >= max_frames) {
            break;
        }
    }
    return frame_list;
}

int main() {
    std::vector<int> result = sequence_tracker(10, 5);
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}