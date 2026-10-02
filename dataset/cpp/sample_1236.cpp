#include <iostream>
#include <vector>

std::vector<int> process_sequence(const std::vector<int>& data, int steps) {
    std::vector<int> result = data;
    for (int i = 0; i < steps; ++i) {
        for (size_t j = 0; j < result.size(); ++j) {
            result[j] += 1;
        }
    }
    return result;
}

int main() {
    std::vector<int> initial_data = {0, 1, 2, 3, 4};
    int steps = 5;
    std::vector<int> result = process_sequence(initial_data, steps);
    for (int x : result) {
        std::cout << x << " ";
    }
    return 0;
}