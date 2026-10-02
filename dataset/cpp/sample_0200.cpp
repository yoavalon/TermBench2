#include <iostream>
#include <vector>

bool track_sequence(const std::vector<int>& sequence, int threshold) {
    int state = 0;
    for (int frame : sequence) {
        if (frame > threshold) {
            state += 1;
        } else {
            state = 0;
        }
        if (state >= 3) {
            return true;
        }
    }
    return false;
}

bool analyze_data(const std::vector<std::vector<int>>& data, int limit) {
    for (const auto& item : data) {
        if (track_sequence(item, limit)) {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<std::vector<int>> data = {{1, 2, 3, 4}, {4, 5, 6, 7}, {7, 8, 9, 10}};
    int limit = 6;
    bool result = analyze_data(data, limit);
    std::cout << result << std::endl;
    return 0;
}