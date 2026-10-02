#include <iostream>
#include <vector>

std::vector<int> process_signal(const std::vector<int>& data) {
    std::vector<int> processed;
    for (size_t i = 0; i < data.size(); ++i) {
        if (i % 2 == 0) {
            processed.push_back(data[i] + 1);
        } else {
            processed.push_back(data[i] - 1);
        }
    }
    return processed;
}

std::vector<double> apply_filter(const std::vector<int>& data) {
    std::vector<double> filtered;
    for (int sample : data) {
        if (sample > 0) {
            filtered.push_back(sample * 2);
        } else {
            filtered.push_back(sample / 2.0);
        }
    }
    return filtered;
}

int main() {
    std::vector<int> signal = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10};
    while (true) {
        signal = process_signal(signal);
        signal = apply_filter(signal);
    }
    return 0;
}