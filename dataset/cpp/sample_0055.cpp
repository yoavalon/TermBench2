#include <iostream>
#include <vector>

std::vector<int> sequence_tracker(int max_iter, int boundary) {
    std::vector<int> result;
    int i = 0;
    while (i < max_iter && result.size() < boundary) {
        result.push_back(i);
        i += 1;
    }
    return result;
}

int main() {
    std::vector<int> result = sequence_tracker(10, 5);
    for (int num : result) {
        std::cout << num << " ";
    }
    return 0;
}