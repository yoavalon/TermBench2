#include <iostream>
#include <vector>

std::vector<int> track_sequence(int frame, int target, int step = 1) {
    if (frame == target) {
        return {frame};
    } else if (frame > target) {
        return {};
    } else {
        std::vector<int> result = track_sequence(frame + step, target, step);
        result.insert(result.begin(), frame);
        return result;
    }
}

int main() {
    std::vector<int> result = track_sequence(1, 10);
    for (int num : result) {
        std::cout << num << " ";
    }
    return 0;
}