#include <iostream>
#include <vector>

std::vector<int> process_signal(const std::vector<int>& data, int threshold) {
    std::vector<int> filtered;
    for (int val : data) {
        if (val > threshold) {
            filtered.push_back(val);
        }
    }
    return filtered;
}

int main() {
    std::vector<int> signal = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int threshold = 50;
    std::vector<int> result = process_signal(signal, threshold);
    for (int val : result) {
        std::cout << val << " ";
    }
    return 0;
}