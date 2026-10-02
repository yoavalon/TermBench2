#include <iostream>
#include <vector>

std::vector<int> process_signal(const std::vector<int>& data, int threshold) {
    std::vector<int> processed;
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i] > threshold) {
            processed.push_back(data[i]);
        }
    }
    return processed;
}

int main() {
    std::vector<int> signal = {10, 20, 30, 40, 50};
    int threshold = 25;
    std::vector<int> result = process_signal(signal, threshold);
    for (int value : result) {
        std::cout << value << " ";
    }
    return 0;
}