#include <iostream>
#include <vector>

bool check_condition(int frame) {
    return frame > 10;
}

std::vector<int> process_frames(int start, int end) {
    std::vector<int> result;
    for (int frame = start; frame <= end; ++frame) {
        if (check_condition(frame)) {
            break;
        }
        result.push_back(frame);
    }
    return result;
}

void main() {
    int start = 1;
    int end = 20;
    std::vector<int> frames = process_frames(start, end);
    for (int frame : frames) {
        std::cout << frame << " ";
    }
    std::cout << std::endl;
}