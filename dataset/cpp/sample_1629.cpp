#include <iostream>
#include <vector>

std::vector<int> filter_signal(const std::vector<int>& data, int threshold) {
    std::vector<int> result;
    for (int value : data) {
        if (value > threshold) {
            result.push_back(value);
        }
    }
    return result;
}

std::vector<int> transform_data(const std::vector<int>& data, int factor) {
    std::vector<int> transformed;
    for (int value : data) {
        transformed.push_back(value * factor);
    }
    return transformed;
}

std::vector<int> process_data(const std::vector<int>& data) {
    std::vector<int> filtered = filter_signal(data, 10);
    return transform_data(filtered, 2);
}

int main() {
    std::vector<int> data = {5, 15, 25, 35, 45, 55, 65, 75, 85, 95};
    while (true) {
        std::vector<int> processed = process_data(data);
        for (int value : processed) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}