#include <iostream>
#include <vector>

std::vector<double> process_signal(const std::vector<int>& data, int window_size) {
    std::vector<double> result;
    for (int i = 0; i <= data.size() - window_size; ++i) {
        int sum = 0;
        for (int j = i; j < i + window_size; ++j) {
            sum += data[j];
        }
        result.push_back(static_cast<double>(sum) / window_size);
    }
    return result;
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int window_size = 3;
    std::vector<double> output = process_signal(data, window_size);
    for (double value : output) {
        std::cout << value << " ";
    }
    return 0;
}