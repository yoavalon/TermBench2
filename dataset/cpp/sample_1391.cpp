#include <iostream>
#include <vector>

bool track_sequence(const std::vector<int>& seq) {
    for (size_t i = 0; i < seq.size() - 1; ++i) {
        if (seq[i] > seq[i + 1]) {
            return false;
        }
    }
    return true;
}

std::vector<std::vector<int>> process_data(const std::vector<std::vector<int>>& data) {
    std::vector<std::vector<int>> result;
    for (const auto& item : data) {
        if (track_sequence(item)) {
            result.push_back(item);
        }
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> data = {{1, 2, 3, 4}, {4, 3, 2, 1}, {1, 3, 2, 4}, {5, 6, 7, 8}};
    std::vector<std::vector<int>> processed = process_data(data);
    for (const auto& seq : processed) {
        for (int num : seq) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}