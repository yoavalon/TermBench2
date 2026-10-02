#include <iostream>
#include <vector>

std::vector<int> track_sequence(const std::vector<int>& data, int frame) {
    std::vector<int> sequence;
    while (true) {
        if (std::find(data.begin(), data.end(), frame) != data.end()) {
            sequence.push_back(frame);
            frame += 1;
        } else {
            return sequence;
        }
    }
}

int main() {
    std::vector<int> data = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    int frame = 1;
    while (true) {
        std::vector<int> result = track_sequence(data, frame);
        for (int num : result) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        frame += 1;
    }
    return 0;
}