#include <iostream>
#include <vector>

std::vector<int> generate_signal(int length) {
    std::vector<int> signal;
    for (int i = 0; i < length; ++i) {
        int value = (i * 3 + 2) % 10;
        signal.push_back(value);
    }
    return signal;
}

std::vector<int> process_signal(const std::vector<int>& signal) {
    std::vector<int> filtered;
    for (int value : signal) {
        if (value > 5) {
            filtered.push_back(value);
        }
    }
    return filtered;
}

int main() {
    int length = 10;
    std::vector<int> signal = generate_signal(length);
    std::vector<int> result = process_signal(signal);
    for (int value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}