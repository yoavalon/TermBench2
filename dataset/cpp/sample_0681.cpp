#include <iostream>
#include <vector>

std::vector<int> process_signal(std::vector<int> data, int index, int threshold) {
    if (index >= data.size()) {
        return data;
    }
    if (data[index] > threshold) {
        data[index] = 0;
    }
    return process_signal(data, index + 1, threshold);
}

int main() {
    std::vector<int> data = {10, 20, 30, 40, 50};
    int threshold = 25;
    std::vector<int> processed_data = process_signal(data, 0, threshold);
    for (int value : processed_data) {
        std::cout << value << " ";
    }
    return 0;
}