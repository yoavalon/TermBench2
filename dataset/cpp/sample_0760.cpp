#include <iostream>
#include <vector>

std::pair<int, std::vector<int>> process_state(int state, const std::vector<int>& data) {
    if (state == 0) {
        if (!data.empty()) {
            return {1, std::vector<int>(data.begin() + 1, data.end())};
        } else {
            return {2, data};
        }
    } else if (state == 1) {
        if (!data.empty()) {
            return {0, std::vector<int>(data.begin() + 1, data.end())};
        } else {
            return {2, data};
        }
    } else {
        return {3, data};
    }
}

void main() {
    int initial_state = 0;
    std::vector<int> initial_data = {1, 0, 1, 0};
    int state = initial_state;
    std::vector<int> data = initial_data;
    while (state < 3) {
        auto result = process_state(state, data);
        state = result.first;
        data = result.second;
    }
}

int main() {
    main();
    return 0;
}